#include "shell.h"
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char buf[READ_BUF_SIZE];
	static size_t buf_pos, buf_len;
	size_t len = 0;
	ssize_t r;
	char *new_p, c;
	if (!lineptr || !n) return (-1);
	if (!*lineptr) { *n = 128; *lineptr = malloc(*n); if (!*lineptr) return (-1); }
	while (1)
	{
		if (buf_pos >= buf_len)
		{
			r = read(fd, buf, READ_BUF_SIZE);
			if (r <= 0) return (len > 0 ? (ssize_t)len : -1);
			buf_len = r;
			buf_pos = 0;
		}
		c = buf[buf_pos++];
		if (len >= *n - 1)
		{
			new_p = _realloc(*lineptr, *n, *n * 2);
			if (!new_p) return (-1);
			*lineptr = new_p;
			*n *= 2;
		}
		(*lineptr)[len++] = c;
		if (c == '\n') { (*lineptr)[len] = '\0'; return (len); }
	}
}
