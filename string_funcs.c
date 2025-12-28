#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
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
 * _strcpy - copies the string pointed to by src
 * @dest: destination
 * @src: source
 * Return: pointer to dest
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
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: pointer to dest
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
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to duplicated string
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
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: difference
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
