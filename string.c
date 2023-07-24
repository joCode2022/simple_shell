#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @q: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *q)
{
	int i = 0;

	if (!q)
		return (0);

	while (*q++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @q1: the first strang
 * @q2: the second strang
 *
 * Return: negative if q1 < q2, positive if q1 > q2, zero if q1 == q2
 */
int _strcmp(char *q1, char *q2)
{
	while (*q1 && *q2)
	{
		if (*q1 != *q2)
			return (*q1 - *q2);
		q1++;
		q2++;
	}
	if (*q1 == *q2)
		return (0);
	else
		return (*q1 < *q2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @heystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *heystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *heystack++)
			return (NULL);
	return ((char *)heystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @sorc: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *sorc)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*sorc)
		*dest++ = *sorc++;
	*dest = *sorc;
	return (ret);
}

