#include "shell.h"
ssize_t _getline(char **lineptr, size_t *n, int fd) { static char buf[1024]; static size_t pos, len; size_t l=0; ssize_t r; char *np, c;
	if(!lineptr||!n)return -1; if(!*lineptr){*n=128;*lineptr=malloc(*n);if(!*lineptr)return -1;}
	while(1){ if(pos>=len){ pos=0; r=read(fd,buf,1024); if(r<=0)return(l>0?(ssize_t)l:-1); len=r; }
	c=buf[pos++]; if(l>=*n-1){ *n*=2; np=_realloc(*lineptr,*n/2,*n); if(!np)return -1; *lineptr=np; } (*lineptr)[l++]=c; if(c=='\n'){(*lineptr)[l]=0;return l;} } }
