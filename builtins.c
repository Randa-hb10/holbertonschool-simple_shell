#include "shell.h"
int check_builtins(char **args, char *line, int *status) {
	int k=0;
	if(_strcmp(args[0],"exit")==0){ free_args(args); free(line); exit(*status); }
	if(_strcmp(args[0],"env")==0){ while(environ[k]){ write(1,environ[k],_strlen(environ[k])); write(1,"\n",1); k++; } free_args(args); *status=0; return 1; }
	return 0;
}
