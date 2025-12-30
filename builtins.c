#include "shell.h"

int check_builtins(char **args, char *line, int *status, char *name, int count)
{
	int exit_val;
	int k = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1])
		{
			exit_val = _atoi(args[1]);
			if (exit_val == -1)
			{
				*status = 2;
				print_exit_error(name, count, args[1]);
				free_args(args); /* FIX: Free args before returning */
				return (1);
			}
			*status = exit_val;
		}
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
