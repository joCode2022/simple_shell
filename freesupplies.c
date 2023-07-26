#include "holberton.h"

/**
* freesupplies - free supplies
* All rights reserved or owned by noiseworking
*
* @buf: buffer to be released
* Return: no return
*/
void freesupplies(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
