#include "holberton.h"

/**
* builtihandler - implementation of built-in functions with handling
* All rights reserved or owned by noiseworking
*
* @command: symbolzed commands
* @line: read input from stdin
* Return: 1 if executed, 0 if not
*/
int builtihandler(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (stringcompares(*command, builtin.env) == 0)
	{
		environmentprint();
		return (1);
	}
	else if (stringcompares(*command, builtin.exit) == 0)
	{
		leavecommand(command, line);
		return (1);
	}
	return (0);
}
