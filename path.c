#include "shell.h"

/**
 * _getenv - gets env variable
 * @name: variable name
 * Return: value or NULL
 */
char *_getenv(const char *name)
{
	int i = 0, j;
	int status;

	while (environ[i])
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != name[j])
			{
				status = 0;
				break;
			}
		}
		if (status)
			return (&environ[i][j + 1]);
		i++;
	}
	return (NULL);
}

/**
 * get_path - resolves command path
 * @cmd: command
 * Return: full path or NULL
 */
char *get_path(char *cmd)
{
	char *path_env, *path_copy, *dir, *full_path;
	struct stat st;
	int len;

	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0)
			return (_strdup(cmd));
		return (NULL);
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = _strdup(path_env);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		len = _strlen(dir) + _strlen(cmd) + 2;
		full_path = malloc(len);
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
