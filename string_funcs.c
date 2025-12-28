#include "shell.h"

/**
 * _strlen - Returns length of string
 * @s: String
 * Return: Length
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/**
 * _strcpy - Copies string
 * @dest: Destination
 * @src: Source
 * Return: Dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!src)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concatenates strings
 * @dest: Destination
 * @src: Source
 * Return: Dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicates string
 * @str: String
 * Return: New string
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = 0;

	if (!str)
		return (NULL);
	while (str[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';
	return (dup);
}

/**
 * _strcmp - Compares strings
 * @s1: First string
 * @s2: Second string
 * Return: Difference
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
