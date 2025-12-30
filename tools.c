#include "shell.h"

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c) return (s);
		s++;
	}
	if (!c) return (s);
	return (NULL);
}

int _atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	if (s[0] == '+') i++;
	for (; s[i]; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		else
			return (-1);
	}
	if (num > INT_MAX) return (-1);
	return (num);
}

void print_exit_error(char *name, int count, char *arg)
{
	_puts_err(name);
	_puts_err(": ");
	print_number(count);
	_puts_err(": exit: Illegal number: ");
	_puts_err(arg);
	_puts_err("\n");
}
