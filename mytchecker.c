#include "holberton.h"
/**
 *mytchecker - checks to see what kind of weather, built-in function
 *All rights reserved or owned by noiseworking
 *@buf: the line derivative of the getline function
 *@cmd: symbolzed input user
 *Return: 1 if cmd excuted 0 if cmd is not executed
 */
int mytchecker(char **cmd, char *buf)
{
	if (builtihandler(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		application(cmd[0], cmd);
		return (1);
	}
	return (0);
}
