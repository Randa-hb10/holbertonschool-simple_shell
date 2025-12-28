#include "shell.h"

/**
 * tokenize - splits string into tokens
 * @line: string to split
 * Return: array of tokens
 */
char **tokenize(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
		return (NULL);
	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
				return (NULL);
		}
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
