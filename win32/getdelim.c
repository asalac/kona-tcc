#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>


signed int getdelim(char **lineptr, size_t *n, int delim, FILE *stream) {
  size_t i;
  if (!lineptr || !n) {
    errno=EINVAL;
    return -1;
  }
  if (!*lineptr) *n=0;
  for (i=0; ; ) {
    int x;
    if (i>=*n) {
      int tmp=*n+100;
      char* new=realloc(*lineptr,tmp);
      if (!new) return -1;
      *lineptr=new; *n=tmp;
    }
    x=fgetc(stream);
    if (x==EOF) { if (!i) return -1; (*lineptr)[i]=0; return i; }
    (*lineptr)[i]=x;
    ++i;
    if (x==delim || i>=*n) break;
  }
  (*lineptr)[i]=0;
  return i;
}

signed int getline(char **lineptr, size_t *n, FILE *stream) {
  return getdelim(lineptr,n,'\n',stream);
}


