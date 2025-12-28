#include "shell.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args;
    
    while (1)
    {
        /* Display prompt only in interactive mode */
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);
        
        /* Read line */
        nread = getline(&line, &len, stdin);
        
        /* Handle EOF (Ctrl+D) */
        if (nread == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            free(line);
            exit(EXIT_SUCCESS);
        }
        
        /* Remove newline */
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';
        
        /* Skip empty lines */
        if (strlen(line) == 0)
            continue;
        
        /* Parse line into arguments */
        args = parse_line(line);
        if (!args)
            continue;
        
        /* Execute command */
        execute_command(args);
        
        /* Clean up */
        free_args(args);
    }
    
    /* This won't be reached due to infinite loop */
    return (0);
}
