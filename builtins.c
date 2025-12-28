#include "shell.h"

/**
 * check_builtins - Checks if the command is a built-in
 * @args: Array of arguments
 * @line: The input line (to free if exit is called)
 * @status: The exit status pointer
 * Return: 1 if built-in executed, 0 otherwise
 */
int check_builtins(char **args, char *line, int *status)
{
	int k = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		free(line);
		exit(*status);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		while (environ[k])
		{
			write(STDOUT_FILENO, environ[k], _strlen(environ[k]));
			write(STDOUT_FILENO, "\n", 1);
			k++;
		}
		free_args(args);
		*status = 0;
		return (1);
	}
	return (0);
}
