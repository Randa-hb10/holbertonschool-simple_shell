#include "shell.h"
char *_strchr(char *s, char c) { while(*s){if(*s==c)return s;s++;} if(!c)return s; return NULL; }
int _atoi(char *s) { int i=0; unsigned int n=0; if(s[0]=='+')i++; for(;s[i];i++){ if(s[i]>='0'&&s[i]<='9')n=n*10+(s[i]-'0'); else return -1; } if(n>INT_MAX)return -1; return n; }
void print_exit_error(char *name, int count, char *arg) { _puts_err(name);_puts_err(": ");print_number(count);_puts_err(": exit: Illegal number: ");_puts_err(arg);_puts_err("\n"); }
int _strncmp(char *s1, char *s2, int n) { int i; for(i=0;i<n;i++){if(s1[i]!=s2[i])return(s1[i]-s2[i]);if(s1[i]==0)return 0;} return 0; }
