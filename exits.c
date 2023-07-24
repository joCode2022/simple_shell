#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@q: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int q)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < q - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < q)
	{
		j = i;
		while (j < q)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@q: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int q)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < q)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < q)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@n: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char n)
{
	do {
		if (*s == n)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

