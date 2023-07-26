#include "holberton.h"

/**
* pathend - path append it adds the path to the command directly
* All rights reserved or owned by noiseworking
*
* @command: the user entered the command
* @path: path command
* Return: the buffer that includes is on my track order on success
*/
char *pathend(char *path, char *command)
{
	char *buf;
	size_t i = 0, j = 0;

	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (stringlength(path) + stringlength(command) + 2));
	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (command[j])
	{
		buf[i + j] = command[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}
