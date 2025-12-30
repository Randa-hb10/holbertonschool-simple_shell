#include "shell.h"

char *_getenv(const char *name)
{
	int i = 0, j, s;

	while (environ[i])
	{
		s = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != name[j])
			{
				s = 0;
				break;
			}
		}
		if (s)
			return (&environ[i][j + 1]);
		i++;
	}
	return (NULL);
}

char *get_path(char *cmd)
{
	char *pe, *pc, *d, *fp;
	struct stat s;
	int l;

	if (_strchr(cmd, '/'))
	{
		if (stat(cmd, &s) == 0)
			return (_strdup(cmd));
		return (NULL);
	}
	pe = _getenv("PATH");
	if (!pe)
		return (NULL);
	pc = _strdup(pe);
	d = strtok(pc, ":");
	while (d)
	{
		l = _strlen(d) + _strlen(cmd) + 2;
		fp = malloc(l);
		_strcpy(fp, d);
		_strcat(fp, "/");
		_strcat(fp, cmd);
		if (stat(fp, &s) == 0)
		{
			free(pc);
			return (fp);
		}
		free(fp);
		d = strtok(NULL, ":");
	}
	free(pc);
	return (NULL);
}
