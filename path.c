#include "shell.h"

/**
 * _getenv - gets environment variable
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
		if (status == 1 && name[j] == '\0')
			return (&environ[i][j + 1]);
		i++;
	}
	return (NULL);
}

/**
 * get_path - locates command in PATH
 * @cmd: command
 * Return: full path or NULL
 */
char *get_path(char *cmd)
{
	char *path_env, *path_copy, *dir, *full_cmd;
	int cmd_len, dir_len;
	struct stat st;

	for (cmd_len = 0; cmd[cmd_len]; cmd_len++)
		if (cmd[cmd_len] == '/')
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
		dir_len = _strlen(dir);
		full_cmd = malloc(dir_len + cmd_len + 2);
		_strcpy(full_cmd, dir);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, cmd);
		if (stat(full_cmd, &st) == 0)
		{
			free(path_copy);
			return (full_cmd);
		}
		free(full_cmd);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
