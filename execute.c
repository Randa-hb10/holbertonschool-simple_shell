#include "shell.h"

/**
 * execute_process - Forks and executes a command
 * @name: Name of the shell program
 * @path: Full path of the command to execute
 * @args: Array of arguments
 * @stat: Pointer to update exit status
 */
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
	{
		perror("fork");
	}
	else
	{
		wait(&s);
		if (WIFEXITED(s))
			*stat = WEXITSTATUS(s);
	}
}
