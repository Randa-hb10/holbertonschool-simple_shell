#include "shell.h"

/**
 * parse_line - Parses a line into arguments
 * @line: Input line
 * Return: Array of arguments (NULL terminated)
 */
char **parse_line(char *line)
{
    char **args = malloc(64 * sizeof(char *));
    char *token;
    int i = 0;
    
    if (!args)
    {
        perror("malloc");
        return (NULL);
    }
    
    token = strtok(line, " \t");
    while (token != NULL && i < 63)
    {
        args[i] = strdup(token);
        if (!args[i])
        {
            perror("strdup");
            free_args(args);
            return (NULL);
        }
        i++;
        token = strtok(NULL, " \t");
    }
    args[i] = NULL;
    
    return (args);
}

/**
 * free_args - Frees arguments array
 * @args: Array to free
 */
void free_args(char **args)
{
    int i;
    
    if (!args)
        return;
    
    for (i = 0; args[i]; i++)
        free(args[i]);
    
    free(args);
}
