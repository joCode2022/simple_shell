#include "holberton.h"

/**
* leavecommand - pivoting or dealing with an exit order
* All rights reserved or owned by noiseworking
*
* @line: Read input from stdin
* @command: symbolzed cmnds
* Return: no return
*/
void leavecommand(char **command, char *line)
{
	free(line);
	freesupplies(command);
	exit(0);
}

