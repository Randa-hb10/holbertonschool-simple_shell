#include "shell.h"

int is_delim(char c, char *delim)
{
	while (*delim)
		if (c == *delim++) return (1);
	return (0);
}

int count_words(char *str, char *delim)
{
	int i, words = 0, state = 0;
	for (i = 0; str[i]; i++)
	{
		if (!is_delim(str[i], delim))
		{
			if (state == 0) { words++; state = 1; }
		}
		else state = 0;
	}
	return (words);
}

char **tokenize(char *line)
{
	char **argv;
	char *delim = " \t\r\n\a";
	int i, j, k, m, words = 0;

	if (line == NULL || *line == '\0') return (NULL);
	words = count_words(line, delim);
	if (words == 0) return (NULL);

	argv = malloc(sizeof(char *) * (words + 1));
	if (!argv) return (NULL);

	for (i = 0, j = 0; j < words; j++)
	{
		while (is_delim(line[i], delim)) i++;
		k = 0;
		while (!is_delim(line[i + k], delim) && line[i + k]) k++;
		argv[j] = malloc((k + 1) * sizeof(char));
		if (!argv[j])
		{
			for (k = 0; k < j; k++) free(argv[k]);
			free(argv); return (NULL);
		}
		for (m = 0; m < k; m++) argv[j][m] = line[i++];
		argv[j][m] = 0;
	}
	argv[j] = NULL;
	return (argv);
}
