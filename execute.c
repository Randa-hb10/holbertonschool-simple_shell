#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: Array of arguments
 * Return: 1 to continue execution
 */
int execute_command(char **args)
{
    pid_t pid;
    int status;
    struct stat st;

    if (!args || !args[0])
        return (1);

    /* Check if command exists */
    if (access(args[0], F_OK) == -1)
    {
        fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
        return (1);
    }

    /* Check if it's a regular file and executable */
    if (stat(args[0], &st) == 0 && S_ISREG(st.st_mode))
    {
        if (access(args[0], X_OK) == -1)
        {
            fprintf(stderr, "./hsh: 1: %s: Permission denied\n", args[0]);
            return (1);
        }
    }

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return (1);
    }
    else if (pid == 0)  /* Child process */
    {
        if (execve(args[0], args, environ) == -1)
        {
            /* This shouldn't happen if we checked above */
            fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else  /* Parent process */
    {
        waitpid(pid, &status, 0);
    }

    return (1);
}

/**
 * print_error - Prints error message
 * @command: Command that failed
 */
void print_error(char *command)
{
    fprintf(stderr, "./hsh: 1: %s: not found\n", command);
}
