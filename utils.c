#include "shell.h"

/**
 * _puts_err - Prints to stderr
 * @str: String
 */
void _puts_err(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i])
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
}

/**
 * print_number - Prints integer to stderr
 * @n: Number
 */
void print_number(int n)
{
	char buffer[12];
	int i = 0;

	if (n == 0)
	{
		_puts_err("0");
		return;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		write(STDERR_FILENO, &buffer[--i], 1);
}

/**
 * print_error - Prints error message
 * @name: Program name
 * @count: Loop count
 * @cmd: Command
 */
void print_error(char *name, int count, char *cmd)
{
	_puts_err(name);
	_puts_err(": ");
	print_number(count);
	_puts_err(": ");
	_puts_err(cmd);
	_puts_err(": not found\n");
}

/**
 * free_args - Frees string array
 * @args: Array
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
