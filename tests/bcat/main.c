#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
	int fd, ret = 0;
	ssize_t in;
	char buffer[BUF_SIZE];

	if(argc != 2){
		printf ("Usage: bcat file\n");
		return -EINVAL;
	}

	fd = open(argv[1], O_RDONLY);
	if (!fd) {
		perror("open");
		return -ENOMEM;
	}

	while (1) {
		in = read(fd, &buffer, BUF_SIZE);

		if (in != -ENOMEM && in < BUF_SIZE) {
			buffer[in] = 0;
		}

		printf("%s", buffer);
		if (in < 0) {
			perror("read");
			ret = in;
			goto out;
		}


	}

out:
	close(fd);
	return ret;
}
