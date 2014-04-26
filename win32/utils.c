#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <math1.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <inttypes.h>

#define __expect(foo,bar) (foo)
#define __likely(foo) __expect((foo),1)  
#define __unlikely(foo) __expect((foo),0) 

// isblank

int isblank (int ch )
{
    return ch == ' '  ||  ch == '\t';
}

// pread

signed int pread(int fd, void *buf, size_t count, off_t offset) {
  return pread(fd,buf,count,offset);
}

// round

double round(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

//strtoll

long long int strtoll(const char *nptr, char **endptr, int base)
{
  int neg=0;
  unsigned long long int v;
  const char*orig=nptr;

  while(isspace(*nptr)) nptr++;

  if (*nptr == '-' && isalnum(nptr[1])) { neg=-1; nptr++; }
  v=strtoull(nptr,endptr,base);
  if (endptr && *endptr==nptr) *endptr=(char *)orig;
  if (v>LLONG_MAX) {
    if (v==0x8000000000000000ull && neg) {
      errno=0;
      return v;
    }
    errno=ERANGE;
    return (neg?LLONG_MIN:LLONG_MAX);
  }
  return (neg?-v:v);
}

intmax_t strtoimax(const char *nptr, char **endptr, int base)
	__attribute__((alias("strtoll")));

// strtoull	

unsigned long long int strtoull(const char *ptr, char **endptr, int base)
{
  int neg = 0, overflow = 0;
  long long int v=0;
  const char* orig;
  const char* nptr=ptr;

  while(isspace(*nptr)) ++nptr;

  if (*nptr == '-') { neg=1; nptr++; }
  else if (*nptr == '+') ++nptr;
  orig=nptr;
  if (base==16 && nptr[0]=='0') goto skip0x;
  if (base) {
    register unsigned int b=base-2;
    if (__unlikely(b>34)) { errno=EINVAL; return 0; }
  } else {
    if (*nptr=='0') {
      base=8;
skip0x:
      if (((*(nptr+1)=='x')||(*(nptr+1)=='X')) && isxdigit(nptr[2])) {
	nptr+=2;
	base=16;
      }
    } else
      base=10;
  }
  while(__likely(*nptr)) {
    register unsigned char c=*nptr;
    c=(c>='a'?c-'a'+10:c>='A'?c-'A'+10:c<='9'?c-'0':0xff);
    if (__unlikely(c>=base)) break;	/* out of base */
    {
      register unsigned long x=(v&0xff)*base+c;
      register unsigned long long w=(v>>8)*base+(x>>8);
      if (w>(ULLONG_MAX>>8)) overflow=1;
      v=(w<<8)+(x&0xff);
    }
    ++nptr;
  }
  if (__unlikely(nptr==orig)) {		/* no conversion done */
    nptr=ptr;
    errno=EINVAL;
    v=0;
  }
  if (endptr) *endptr=(char *)nptr;
  if (overflow) {
    errno=ERANGE;
    return ULLONG_MAX;
  }
  return (neg?-v:v);
}

unsigned long long int strtouq(const char *nptr, char **endptr, int base)
	__attribute__((alias("strtoull")));

uintmax_t strtoumax(const char *nptr, char **endptr, int base)
	__attribute__((alias("strtoull")));
	
//fpclassiffy

int __cdecl __fpclassify (double x){
  unsigned short sw;
  //__asm__ ("fxam; fstsw %%ax;": "=a" (sw): "t" (x));
 __asm__ ("fldl %1;fxam;fstsw %%ax;" : "=a" (sw) : "g" (x) );
  return sw & (FP_NAN | FP_NORMAL | FP_ZERO );
}

int __cdecl __fpclassifyf (float x){
  unsigned short sw;
  //__asm__ ("fxam; fstsw %%ax;": "=a" (sw): "t" (x));
  __asm__ ("fldl %1;fxam;fstsw %%ax;" : "=a" (sw) : "g" (x) );
  return sw & (FP_NAN | FP_NORMAL | FP_ZERO );
}