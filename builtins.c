#include "shell.h"

int check_builtins(char **args, char *line, int *status, char *name, int count)
{
	int exit_val;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1])
		{
			exit_val = _atoi(args[1]);
			if (exit_val == -1)
			{
				*status = 2;
				print_exit_error(name, count, args[1]);
				free_args(args);
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
		print_env();
		free_args(args);
		*status = 0;
		return (1);
	}
	if (_strcmp(args[0], "setenv") == 0)
	{
		if (_mysetenv(args) != 0)
			*status = 1;
		else
			*status = 0;
		free_args(args);
		return (1);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (_myunsetenv(args) != 0)
			*status = 1;
		else
			*status = 0;
		free_args(args);
		return (1);
	}
	return (0);
}
