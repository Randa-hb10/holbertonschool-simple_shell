#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count (unused)
 * @argv: Argument vector
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	char *line = NULL, *cmd_path = NULL, **args = NULL;
	size_t len = 0;
	ssize_t nread;
	int loop = 0, status = 0;
	(void)argc;

	while (1)
	{
		loop++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
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
		cmd_path = get_path(args[0]);
		if (cmd_path)
		{
			execute_process(argv[0], cmd_path, args, &status);
			free(cmd_path);
		}
		else
		{
			print_error(argv[0], loop, args[0]);
			status = 127;
		}
		free_args(args);
	}
	free(line);
	return (status);
}
