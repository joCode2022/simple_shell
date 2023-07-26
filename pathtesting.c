#include "holberton.h"

/**
* pathtesting - checks whether path is valid
* All rights reserved or owned by noiseworking
* @command: The user made or entered the command
* @path: symbolzed
*
* Return: directed in order to succeed
*/
char *pathtesting(char **path, char *command)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = pathend(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
