#ifndef SHELL_H
#define SHELL_H

/* ============ REQUIRED HEADERS ============ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* ============ CONSTANTS ============ */
#define MAX_ARGS 64
#define BUFFER_SIZE 1024

/* ============ EXTERNAL VARIABLES ============ */
extern char **environ;

/* ============ FUNCTION PROTOTYPES ============ */

/* Main functions */
void shell_loop(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);

/* Execution functions */
int launch_process(char **args);

/* Helper functions */
void display_prompt(void);
void handle_eof(void);
int is_empty_line(char *line);
void free_args(char **args);

/* Error handling */
void print_error(char *command);

#endif /* SHELL_H */
