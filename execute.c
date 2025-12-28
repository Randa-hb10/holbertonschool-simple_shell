#include "shell.h"

/**
 * execute_cmd - fork and execute command
 * @cmd: command to execute
 */
void execute_cmd(char *cmd)
{
    pid_t pid;
    int status;
    char *av[2];

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        av[0] = cmd;
        av[1] = NULL;

        execve(cmd, av, environ);
        perror("./hsh");
        exit(1);
    }
    else
        waitpid(pid, &status, 0);
}
