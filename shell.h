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
#include <limits.h>
#define READ_BUF_SIZE 1024
extern char **environ;
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void _puts_err(char *str);
void print_number(int n);
void print_error(char *name, int count, char *cmd);
void free_args(char **args);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **tokenize(char *line);
char *_getenv(const char *name);
char *get_path(char *cmd);
int check_builtins(char **args, char *line, int *status);
void execute_process(char *name, char *path, char **args, int *stat);
void handle_execution(char *name, char **args, int count, int *stat);
ssize_t _getline(char **lineptr, size_t *n, int fd);
#endif
