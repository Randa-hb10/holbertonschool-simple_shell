#include "shell.h"

/**
 * main - simple shell entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL, **argv = NULL, *cmd_path = NULL;
	size_t len = 0;
	ssize_t read;
	int status, count = 0;
	pid_t pid;
	(void)ac;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		argv = tokenize(line);
		if (!argv || !argv[0])
		{
			free(argv);
			continue;
		}
		cmd_path = get_path(argv[0]);
		if (cmd_path)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(cmd_path, argv, environ) == -1)
					exit(127);
			}
			else
				wait(&status);
			free(cmd_path);
		}
		else
			print_error(av[0], count, argv[0]);
		free(argv);
	}
	free(line);
	return (0);
}
