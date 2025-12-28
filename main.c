#include "shell.h"

/**
 * handle_cmd - Handles command execution
 * @name: Program name
 * @count: Loop count
 * @args: Arguments
 * @status: Status pointer
 */
void handle_cmd(char *name, int count, char **args, int *status)
{
	char *path;

	path = get_path(args[0]);
	if (path)
	{
		execute_process(name, path, args, status);
		free(path);
	}
	else
	{
		print_error(name, count, args[0]);
		*status = 127;
	}
}

/**
 * main - Entry point for the simple shell
 * @argc: Argument count (unused)
 * @argv: Argument vector
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	char *line = NULL, **args = NULL;
	size_t len = 0;
	ssize_t n;
	int count = 0, status = 0;
	(void)argc;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		n = getline(&line, &len, stdin);
		if (n == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		args = tokenize(line);
		if (!args[0])
		{
			free_args(args);
			continue;
		}
		if (check_builtins(args, line, &status))
			continue;
		handle_cmd(argv[0], count, args, &status);
		free_args(args);
	}
	free(line);
	return (status);
}
