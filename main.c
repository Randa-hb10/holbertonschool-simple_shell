#include "shell.h"

int main(int ac, char **av)
{
	char *line = NULL, **args = NULL;
	size_t len = 0;
	ssize_t n;
	int count = 0, status = 0;
	(void)ac;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO)) write(STDOUT_FILENO, "($) ", 4);
		n = _getline(&line, &len, STDIN_FILENO);
		if (n == -1)
		{
			if (isatty(STDIN_FILENO)) write(STDOUT_FILENO, "\n", 1);
			break;
		}
		args = tokenize(line);
		if (!args[0]) { free_args(args); continue; }
		if (check_builtins(args, line, &status)) continue;
		handle_execution(av[0], args, count, &status);
		free_args(args);
	}
	free(line);
	return (status);
}
