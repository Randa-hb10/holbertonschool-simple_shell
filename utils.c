#include "shell.h"

/**
 * _puts_err - prints string to stderr
 * @str: string
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
 * print_number - prints integer to stderr
 * @n: integer
 */
void print_number(int n)
{
	unsigned int m;

	if (n < 0)
	{
		m = -n;
		write(STDERR_FILENO, "-", 1);
	}
	else
		m = n;
	if (m / 10)
		print_number(m / 10);
	write(STDERR_FILENO, &"0123456789"[m % 10], 1);
}

/**
 * print_error - prints error message
 * @name: program name
 * @count: line count
 * @cmd: command
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
