#include "holberton.h"

/**
* findlocatepath - finds path from global enviroment
* All rights reserved or owned by noiseworking
*
* Return: NULL if the path is not detected, or the path if it is detected
*/
char *findlocatepath(void)
{
	int x;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (stringncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
