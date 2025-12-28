#include "shell.h"

/**
 * execute_process - Forks and executes a command
 * @prog_name: Name of the shell program (argv[0])
 * @cmd_path: Full path of the command to execute
 * @args: Array of arguments
 * @status: Pointer to update exit status
 */
void execute_process(char *prog_name, char *cmd_path, char **args, int *status)
{
	pid_t pid;
	int s;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
			perror(prog_name);
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
			*status = WEXITSTATUS(s);
	}
}
