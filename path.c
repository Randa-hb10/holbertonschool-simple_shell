#include "shell.h"

char *_getenv(const char *name)
{
	int i = 0, j, s;
	while (environ[i])
	{
		s = 1;
		for (j = 0; environ[i][j] != '='; j++)
			if (environ[i][j] != name[j])
			{
				s = 0;
				break;
			}
		if (s)
			return (&environ[i][j + 1]);
		i++;
	}
	return (NULL);
}

char *get_path(char *cmd)
{
	char *pe, *fp;
	struct stat s;
	int i = 0, j = 0, len;

	if (_strchr(cmd, '/'))
	{
		if (stat(cmd, &s) == 0)
			return (_strdup(cmd));
		return (NULL);
	}
	pe = _getenv("PATH");
	if (!pe)
		return (NULL);

	while (pe[i])
	{
		if (pe[i] == ':' || pe[i] == '\0')
		{
			len = i - j;
			fp = malloc(len + _strlen(cmd) + 2);
			if (len > 0)
			{
				_strcpy(fp, pe + j);
				fp[len] = '\0';
				_strcat(fp, "/");
			}
			else
				_strcpy(fp, "./");
			
			_strcat(fp, cmd);
			if (stat(fp, &s) == 0)
				return (fp);
			free(fp);
			if (pe[i] == '\0')
				break;
			j = i + 1;
		}
		i++;
	}
	return (NULL);
}
