#include "shell.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: status
 */
int main(int ac, char **av)
{
	char *line = NULL, **args = NULL;
	size_t len = 0;
	ssize_t n;
	int count = 0, status = 0, fd = STDIN_FILENO;

	/* Check if file argument is provided (Task 22) */
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			_puts_err(av[0]);
			_puts_err(": 0: Can't open ");
			_puts_err(av[1]);
			_puts_err("\n");
			return (127);
		}
	}

	while (1)
	{
		count++;
		/* Only print prompt if interactive AND reading from stdin */
		if (isatty(STDIN_FILENO) && fd == STDIN_FILENO)
			write(STDOUT_FILENO, "($) ", 4);

		n = _getline(&line, &len, fd);
		
		if (n == -1) /* End of file or Error */
		{
			free(line);
			if (fd != STDIN_FILENO) close(fd);
			exit(status);
		}

		args = tokenize(line);
		if (!args[0])
		{
			free_args(args);
			continue;
		}

		if (check_builtins(args, line, &status, av[0], count))
			continue;

		handle_execution(av[0], args, count, &status);
		free_args(args);
	}
	free(line);
	if (fd != STDIN_FILENO) close(fd);
	return (status);
}
