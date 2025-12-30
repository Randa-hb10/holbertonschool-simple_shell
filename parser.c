#include "shell.h"

char **tokenize(char *line)
{
	int bs = 64, i = 0;
	char **tks = malloc(bs * sizeof(char *));
	char *t;

	if (!tks)
		exit(1);

	t = strtok(line, " \t\r\n\a");
	while (t)
	{
		tks[i++] = _strdup(t);
		if (i >= bs)
		{
			bs += 64;
			tks = _realloc(tks, (bs - 64) * sizeof(char *), bs * sizeof(char *));
			if (!tks)
				exit(1);
		}
		t = strtok(NULL, " \t\r\n\a");
	}
	tks[i] = NULL;
	return (tks);
}
