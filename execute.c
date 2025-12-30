#include "shell.h"

void execute_process(char *name, char *path, char **args, int *stat)
{
	pid_t pid;
	int s;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
			perror(name);
		exit(2);
	}
	else if (pid < 0)
		perror("fork");
	else
	{
		wait(&s);
		if (WIFEXITED(s))
			*stat = WEXITSTATUS(s);
	}
}

void handle_execution(char *name, char **args, int count, int *stat)
{
	char *path = get_path(args[0]);
	if (path)
	{
		execute_process(name, path, args, stat);
		free(path);
	}
	else
	{
		print_error(name, count, args[0]);
		*stat = 127;
	}
}
