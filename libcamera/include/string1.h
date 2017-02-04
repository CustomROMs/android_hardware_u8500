#ifndef STRING_H
#define STRING_H

#include <sys/types.h>

extern "C" char* strerror(int);
extern "C" size_t strlen(const char *);
extern "C" int    strcmp(const char *, const char *);
extern "C" char* strcpy(char* dest, const char* src);
extern "C" void* memcpy(void* __restrict, const void* __restrict, size_t);
#if defined(__USE_GNU)
extern "C" void*  mempcpy(void* __restrict, const void* __restrict, size_t);
#endif
extern "C" void*  memmove(void *, const void *, size_t);
extern "C" void*  memset(void *, int, size_t);
extern "C" void*  memmem(const void *, size_t, const void *, size_t);

extern "C" char*  strchr(const char *, int);
extern "C" char* __strchr_chk(const char *, int, size_t);

extern "C" char*  strrchr(const char *, int);
extern "C" char* __strrchr_chk(const char *, int, size_t);

extern "C" size_t strlen(const char *);
extern "C" size_t __strlen_chk(const char *, size_t);
extern "C" int    strcmp(const char *, const char *);
extern "C" char*  stpcpy(char* __restrict, const char* __restrict);
extern "C" char*  strcpy(char* __restrict, const char* __restrict);
extern "C" char*  strcat(char* __restrict, const char* __restrict);

#if 0
int strcasecmp(const char*, const char*);
int strcasecmp_l(const char*, const char*, locale_t);
int strncasecmp(const char*, const char*, size_t);
int strncasecmp_l(const char*, const char*, size_t, locale_t);
#endif

extern "C" char*  strdup(const char *);

extern "C" char*  strstr(const char *, const char *);
extern "C" char*  strcasestr(const char *haystack, const char *needle);
extern "C" char*  strtok(char* __restrict, const char* __restrict);
extern "C" char*  strtok_r(char* __restrict, const char* __restrict, char** __restrict);

extern "C" char* strerror(int);
//extern "C" char* strerror_l(int, locale_t);
#if defined(__USE_GNU)
extern "C" char* strerror_r(int, char*, size_t) __RENAME(__gnu_strerror_r);
#else /* POSIX */
extern "C" int strerror_r(int, char*, size_t);
#endif

extern "C" size_t strnlen(const char *, size_t);
extern "C" char*  strncat(char* __restrict, const char* __restrict, size_t);
extern "C" char*  strndup(const char *, size_t);
extern "C" int    strncmp(const char *, const char *, size_t);
extern "C" char*  stpncpy(char* __restrict, const char* __restrict, size_t);
extern "C" char*  strncpy(char* __restrict, const char* __restrict, size_t);

#if 0
extern size_t strlcat(char* __restrict, const char* __restrict, size_t);
extern size_t strlcpy(char* __restrict, const char* __restrict, size_t);

extern size_t strcspn(const char *, const char *);
extern char*  strpbrk(const char *, const char *);
extern char*  strsep(char** __restrict, const char* __restrict);
extern size_t strspn(const char *, const char *);

extern char*  strsignal(int  sig);

extern int    strcoll(const char *, const char *);
extern size_t strxfrm(char* __restrict, const char* __restrict, size_t);

extern int    strcoll_l(const char *, const char *, locale_t);
extern size_t strxfrm_l(char* __restrict, const char* __restrict, size_t, locale_t);

#if defined(__USE_GNU) && !defined(basename)
/*
 * glibc has a basename in <string.h> that's different to the POSIX one in <libgen.h>.
 * It doesn't modify its argument, and in C++ it's const-correct.
 */

#if defined(__cplusplus)
extern "C++" char* basename(char*) __RENAME(__gnu_basename) __nonnull((1));
extern "C++" const char* basename(const char*) __RENAME(__gnu_basename) __nonnull((1));
#else
extern char* basename(const char*) __RENAME(__gnu_basename) __nonnull((1));
#endif
#endif

extern "C" void* __memchr_chk(const void*, int, size_t, size_t);
__errordecl(__memchr_buf_size_error, "memchr called with size bigger than buffer");

extern "C" void* __memrchr_chk(const void*, int, size_t, size_t);
#endif

#endif
