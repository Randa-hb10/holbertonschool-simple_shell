#include "shell.h"

/**
 * print_prompt - prints shell prompt
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}

