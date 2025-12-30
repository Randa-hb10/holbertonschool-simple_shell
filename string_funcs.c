#include "shell.h"

int _strlen(char *s)
{
	int i = 0;
	if (!s) return (0);
	while (s[i]) i++;
	return (i);
}

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	if (!src) return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;
	while (dest[i]) i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char *_strdup(char *str)
{
	char *d;
	int i = 0, l = 0;
	if (!str) return (NULL);
	while (str[l]) l++;
	d = malloc(l + 1);
	if (!d) return (NULL);
	for (i = 0; i < l; i++) d[i] = str[i];
	d[l] = '\0';
	return (d);
}

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2) return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
