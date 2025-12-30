#include "shell.h"

void _puts_err(char *str)
{
	int i = 0;
	if (!str) return;
	while (str[i]) { write(STDERR_FILENO, &str[i], 1); i++; }
}

void print_number(int n)
{
	char buffer[12];
	int i = 0;
	if (n == 0) { _puts_err("0"); return; }
	while (n > 0) { buffer[i++] = (n % 10) + '0'; n /= 10; }
	while (i > 0) write(STDERR_FILENO, &buffer[--i], 1);
}

void print_error(char *name, int count, char *cmd)
{
	_puts_err(name); _puts_err(": ");
	print_number(count); _puts_err(": ");
	_puts_err(cmd); _puts_err(": not found\n");
}

void free_args(char **args)
{
	int i = 0;
	if (!args) return;
	while (args[i]) { free(args[i]); i++; }
	free(args);
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i;
	if (new_size == old_size) return (ptr);
	if (new_size == 0 && ptr != NULL) { free(ptr); return (NULL); }
	if (ptr == NULL) return (malloc(new_size));
	p = malloc(new_size);
	if (!p) return (NULL);
	for (i = 0; i < old_size && i < new_size; i++) ((char *)p)[i] = ((char *)ptr)[i];
	free(ptr);
	return (p);
}
