#include "shell.h"

/**
 * main - entry point of simple shell
 * Return: 0
 */
int main(void)
{
    char *line = NULL;
    size_t cap = 0;
    ssize_t nread;
    char *cmd;

    while (1)
    {
        print_prompt();

        nread = getline(&line, &cap, stdin);
        if (nread == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            free(line);
            exit(0);
        }

        cmd = strtok(line, " \t\r\n");
        if (!cmd)
            continue;

        execute_cmd(cmd);
    }
    free(line);
    return (0);
}
