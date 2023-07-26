#include "holberton.h"

/**
* environmentprint - prints environment mix to stdout
* All rights reserved or owned by noiseworking
* Return: nothing 0
*/
void environmentprint(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], stringlength(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
