#include "shell.h"

/**
 * create_new_entry - creates a "NAME=VALUE" string
 * @name: var name
 * @value: var value
 * Return: new allocated string
 */
char *create_new_entry(char *name, char *value)
{
	char *new_entry;
	int len1 = _strlen(name);
	int len2 = _strlen(value);

	new_entry = malloc(len1 + len2 + 2); /* +2 for '=' and null */
	if (!new_entry) return (NULL);

	_strcpy(new_entry, name);
	_strcat(new_entry, "=");
	_strcat(new_entry, value);
	return (new_entry);
}

/**
 * _mysetenv - initializes or modifies an environment variable
 * @args: arguments (setenv VARIABLE VALUE)
 * Return: 0 on success, 1 on error
 */
int _mysetenv(char **args)
{
	int i, j, k;
	char *new_entry;
	char **new_environ;

	if (!args[1] || !args[2])
	{
		_puts_err("Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	new_entry = create_new_entry(args[1], args[2]);
	if (!new_entry) return (1);

	/* Check if variable exists */
	for (i = 0; environ[i]; i++)
	{
		for (k = 0; args[1][k] && environ[i][k] == args[1][k]; k++)
			;
		if (args[1][k] == '\0' && environ[i][k] == '=')
		{
			/* Found, replace it (Memory leak possible here if old was malloced, but simple shell) */
			environ[i] = new_entry;
			return (0);
		}
	}

	/* Not found, add it (resize array) */
	new_environ = malloc(sizeof(char *) * (i + 2));
	if (!new_environ) { free(new_entry); return (1); }

	for (j = 0; j < i; j++)
		new_environ[j] = environ[j];
	
	new_environ[j] = new_entry;
	new_environ[j + 1] = NULL;
	
	/* Update global environ (Note: we don't free old environ array here to be safe with OS memory) */
	environ = new_environ;
	return (0);
}

/**
 * _myunsetenv - removes an environment variable
 * @args: arguments (unsetenv VARIABLE)
 * Return: 0 on success, 1 on error
 */
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
			/* Found, shift remaining elements down */
			/* free(environ[i]); // Skipping free for safety with OS memory */
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
			return (0);
		}
	}
	return (0); /* Not found is not an error typically */
}
