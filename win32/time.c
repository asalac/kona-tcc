#include <windows.h> 
#include <sys/time.h>

typedef unsigned long size_t;

/* Offset between 1/1/1601 and 1/1/1970 in 100 nanosec units */

#define _W32_FT_OFFSET (116444736000000000ULL)


#define timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)

#define timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0

int gettimeofday(struct timeval *tp, void *tf)
{
  union {
    unsigned long long ns100; /*time since 1 Jan 1601 in 100ns units */
    FILETIME ft;
  }  _now;

  if(tp) {
      GetSystemTimeAsFileTime (&_now.ft);
      tp->tv_usec=(long)((_now.ns100 / 10ULL) % 1000000ULL );
      tp->tv_sec= (long)((_now.ns100 - _W32_FT_OFFSET) / 10000000ULL);
  }
  /* Always return 0 as per Open Group Base Specifications Issue 6.
     Do not set errno on error.  */
  return 0;
}

int setenv(const char *name, const char *value, int overwrite)
{
    int result = 0;
    if (overwrite || !getenv(name)) {
        size_t length = strlen(name) + strlen(value) + 2;
        char *string = malloc(length);
        snprintf(string, length, "%s=%s", name, value);
        result = putenv(string);

        /* Windows takes a copy and does not continue to use our string.
         * Therefore it can be safely freed on this platform.  POSIX code
         * typically has to leak the string because according to the spec it
         * becomes part of the environment.
         */
        free(string);
    }
    return result;
}
