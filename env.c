#include "shell.h"

void print_env(void)
{
	int i = 0;
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

char *create_new_entry(char *name, char *value)
{
	char *new_entry;
	int len1 = _strlen(name);
	int len2 = _strlen(value);

	new_entry = malloc(len1 + len2 + 2);
	if (!new_entry)
		return (NULL);

	_strcpy(new_entry, name);
	_strcat(new_entry, "=");
	_strcat(new_entry, value);
	return (new_entry);
}

int _mysetenv(char **args)
{
	int i, j, k;
	char *new_entry;
	char **new_environ;

	if (!args[1])
	{
		print_env();
		return (0);
	}
	if (!args[2])
	{
		_puts_err("Usage: setenv VARIABLE VALUE\n");
		return (1);
	}

	new_entry = create_new_entry(args[1], args[2]);
	if (!new_entry)
		return (1);

	for (i = 0; environ[i]; i++)
	{
		for (k = 0; args[1][k] && environ[i][k] == args[1][k]; k++)
			;
		if (args[1][k] == '\0' && environ[i][k] == '=')
		{
			environ[i] = new_entry;
			return (0);
		}
	}

	new_environ = malloc(sizeof(char *) * (i + 2));
	if (!new_environ)
	{
		free(new_entry);
		return (1);
	}

	for (j = 0; j < i; j++)
		new_environ[j] = environ[j];
	new_environ[j] = new_entry;
	new_environ[j + 1] = NULL;
	environ = new_environ;
	return (0);
}

int _myunsetenv(char **args)
{
	int i, j, k;

	if (!args[1])
	{
		_puts_err("Usage: unsetenv VARIABLE\n");
		return (1);
	}

	for (i = 0; environ[i]; i++)
	{
		for (k = 0; args[1][k] && environ[i][k] == args[1][k]; k++)
			;
		if (args[1][k] == '\0' && environ[i][k] == '=')
		{
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
			return (0);
		}
	}
	return (0);
}
