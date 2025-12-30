#include "shell.h"
void _puts_err(char *str) { int i=0; if(!str)return; while(str[i]){write(2,&str[i],1);i++;} }
void print_number(int n) { char b[12]; int i=0; if(n==0){_puts_err("0");return;} while(n>0){b[i++]=(n%10)+'0';n/=10;} while(i>0)write(2,&b[--i],1); }
void print_error(char *name, int count, char *cmd) { _puts_err(name);_puts_err(": ");print_number(count);_puts_err(": ");_puts_err(cmd);_puts_err(": not found\n"); }
void free_args(char **args) { int i=0; if(!args)return; while(args[i]){free(args[i]);i++;} free(args); }
void *_realloc(void *ptr, unsigned int os, unsigned int ns) { char *p; unsigned int i; if(ns==os)return ptr; if(ns==0&&ptr){free(ptr);return NULL;} if(!ptr)return malloc(ns); p=malloc(ns); if(!p)return NULL; for(i=0;i<os&&i<ns;i++)((char*)p)[i]=((char*)ptr)[i]; free(ptr); return p; }
