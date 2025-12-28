#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

/* string_funcs.c */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* utils.c */
void _puts_err(char *str);
void print_number(int n);
void print_error(char *name, int count, char *cmd);
void free_args(char **args);

/* parser.c */
char **tokenize(char *line);

/* path.c */
char *_getenv(const char *name);
char *get_path(char *cmd);

/* builtins.c */
int check_builtins(char **args, char *line, int *status);

/* execute.c */
void execute_process(char *prog_name, char *cmd_path, char **args, int *status);

#endif
