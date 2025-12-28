#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL, *cmd_path = NULL, **args = NULL;
	size_t len = 0;
	ssize_t nread;
	int loop_count = 0, status, k;
	pid_t pid;
	(void)argc;

	while (1)
	{
		loop_count++;
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

		if (_strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			free(line);
			exit(0);
		}
		if (_strcmp(args[0], "env") == 0)
		{
			k = 0;
			while (environ[k])
			{
				write(STDOUT_FILENO, environ[k], _strlen(environ[k]));
				write(STDOUT_FILENO, "\n", 1);
				k++;
			}
			free_args(args);
			continue;
		}

		cmd_path = get_path(args[0]);
		if (cmd_path)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(cmd_path, args, environ) == -1)
					perror(argv[0]);
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
				perror("fork");
			else
				wait(&status);
			free(cmd_path);
		}
		else
		{
			print_error(argv[0], loop_count, args[0]);
		}
		free_args(args);
	}
	free(line);
	return (0);
}
