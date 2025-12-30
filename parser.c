#include "shell.h"

int is_delim(char c, char *delim)
{
	while (*delim)
		if (c == *delim++) return (1);
	return (0);
}

int count_words(char *str, char *delim)
{
	int i, w = 0, s = 0;
	for (i = 0; str[i]; i++)
	{
		if (!is_delim(str[i], delim))
		{
			if (s == 0) { w++; s = 1; }
		}
		else s = 0;
	}
	return (w);
}

char **tokenize(char *line)
{
	char **av, *d = " \t\r\n\a";
	int i, j, k, m, w;

	if (!line || !*line) return (NULL);
	w = count_words(line, d);
	if (w == 0) return (NULL);
	
	av = malloc(sizeof(char *) * (w + 1));
	if (!av) return (NULL);

	for (i = 0, j = 0; j < w; j++)
	{
		while (is_delim(line[i], d)) i++;
		k = 0;
		while (!is_delim(line[i + k], d) && line[i + k]) k++;
		
		av[j] = malloc(k + 1);
		if (!av[j]) return (NULL);
		
		for (m = 0; m < k; m++) av[j][m] = line[i++];
		av[j][m] = 0;
	}
	av[j] = NULL;
	return (av);
}
