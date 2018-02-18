#include <assert.h>
#include <error.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
//#include "botutil.h"

#define verify assert

__attribute__((format(printf, 6, 7), noreturn))
void requiref_fail(
		char const *expr,
		int code,
		char const *file,
		int line,
		char const *func,
		char const *fmt,
		...)
{
	int const errnum = errno;
	fprintf(stderr, "%s: %s:%d: %s: '%s' failed",
			"program_invocation_name", file, line, func, expr);
	if (fmt != NULL)
	{
		fprintf(stderr, ": ");
		va_list ap;
		va_start(ap, fmt);
		vfprintf(stderr, fmt, ap);
		va_end(ap);
	}
	if (errnum != 0)
	{
		fprintf(stderr, ": %s", strerror(errnum));
	}
	fprintf(stderr, ".\n");
	exit(code);
}

#define requiref(expr, code, fmt, ...) \
	((expr) || (requiref_fail(#expr, code, __FILE__, __LINE__, __PRETTY_FUNCTION__, fmt, ##__VA_ARGS__), false))

#define require2(expr, code) requiref(expr, code, NULL)

#define require(expr) require2(expr, EXIT_FAILURE)

// returns the pid of a tracer, 0 if there is none
// the function will asplode if something is not right
pid_t get_tracer_pid(pid_t pid)
{
	pid_t tracepid = -1;
	char *sttspath = NULL;
	verify(-1 != asprintf(&sttspath, "/proc/%d/status", pid));
	FILE *sttsfile = fopen(sttspath, "r");
	assert(sttsfile != NULL);
	free(sttspath);
	char *line = NULL;
	size_t linesize;
	while (-1 != getline(&line, &linesize, sttsfile))
	{
		char const *const fieldnam = "TracerPid:";
		if (0 == strncmp(line, fieldnam, strlen(fieldnam)))
		{
			verify(1 == sscanf(line + strlen(fieldnam), "%d", &tracepid));
			break;
		}
	}
	require(tracepid != -1);
	free(line);
	verify(0 == fclose(sttsfile));
	return tracepid;
}

// wait for tracee to receive SIGSTOP
// pass all other signals on to tracee
void wait_until_tracee_stops(pid_t pid)
{
	while (true)
	{
		int status = 0;
		pid_t waitret = waitpid(pid, &status, 0);
		if (waitret != pid)
		{
			perror("waitpid()");
			exit(1);
		}
		if (!WIFSTOPPED(status))
		{
			fprintf(stderr, "Unhandled status change: %d\n", status);
			exit(1);
		}
		if (WSTOPSIG(status) == SIGSTOP)
		{
			return;
		}
		else
		{
			int signal = WSTOPSIG(status);
			fprintf(stderr, "Passing signal to child: %d\n", signal);
			long ptraceret = ptrace(PTRACE_CONT, pid, NULL, WSTOPSIG(status));
			if (ptraceret != 0)
			{
				perror("ptrace(PTRACE_CONT)");
				exit(1);
			}
		}
	}
}


#define BLOCK_SIGNALS 1

/*
Returns
	0: success,
	1: general failure,
	2: argument issue,
	3: attach failed, try again
*/
int main(int argc, char **argv)
{
	/* parse arguments */

	if (argc < 4)
	{
		fprintf(stderr, "Missing arguments\n");
		return 2;
	}

	pid_t const pid = atoi(argv[1]);
	uintptr_t const address = strtoul(argv[2], NULL, 0);
	size_t const size = strtoul(argv[3], NULL, 0);

	if (pid <= 0 || address == ULONG_MAX || size == ULONG_MAX)
	{
		fprintf(stderr, "Invalid arguments\n");
		return 2;
	}

	/* prepare for memory reads */

	char *mempath = NULL;
	verify(-1 != asprintf(&mempath, "/proc/%d/mem", pid));
	char *outbuf = malloc(size);
	assert(outbuf != NULL);

	/* attach to target process */

	// block all signals, we can't blow up while waiting for the child to stop
	// or the child will freeze when it's SIGSTOP arrives and we don't clear it
#if defined(BLOCK_SIGNALS)
	sigset_t oldset;
	{
		sigset_t newset;
		verify(0 == sigfillset(&newset));
		// out of interest, we ensure the most likely signal is present
		assert(1 == sigismember(&newset, SIGINT));
		verify(0 == sigprocmask(SIG_BLOCK, &newset, &oldset));
	}
#endif

	// attach or exit with code 3
	if (0 != ptrace(PTRACE_ATTACH, pid, NULL, NULL))
	{
		int errattch = errno;
		// if ptrace() gives EPERM, it might be because another process
		// is already attached, there's no guarantee it's still attached by
		// the time we check so this is a best attempt to determine who is
		if (errattch == EPERM)
		{
			pid_t tracer = get_tracer_pid(pid);
			if (tracer != 0)
			{
				fprintf(stderr, "Process %d is currently attached\n", tracer);
				return 3;
			}
		}
		error(errattch == EPERM ? 3 : 1, errattch, "ptrace(PTRACE_ATTACH)");
	}

	//verify(0 == raise(SIGINT));

	wait_until_tracee_stops(pid);

#if defined(BLOCK_SIGNALS)
	verify(0 == sigprocmask(SIG_SETMASK, &oldset, NULL));
#endif

	int memfd = open(mempath, O_RDONLY);
	assert(memfd != -1);

	// read bytes from the tracee's memory
	verify(size == pread(memfd, outbuf, size, address));

	verify(!close(memfd));
	verify(!ptrace(PTRACE_DETACH, pid, NULL, 0));

	// write requested memory region to stdout
	// byte count in nmemb to handle writes of length 0
	verify(size == fwrite(outbuf, 1, size, stdout));

	free(outbuf);
	free(mempath);

	return 0;
}
