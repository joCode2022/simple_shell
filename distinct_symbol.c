#include "holberton.h"

/**
* distinct_symbol - generates symbols from a specific entry
* All rights reserved or owned by noiseworking
* @line: to be able to access its encoding symbolzed
*
* Return: set of strings
*/
char **distinct_symbol(char *line)
{
	char *buf = NULL, *bufp = NULL, *symbol = NULL, *delim = " :\t\r\n";
	char **symbols = NULL;
	int symbolsize = 1;
	size_t index = 0, flag = 0;

	buf = stringdupicates(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (stringcharacter(delim, *bufp) != NULL && flag == 0)
		{
			symbolsize++;
			flag = 1;
		}
		else if (stringcharacter(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	symbols = malloc(sizeof(char *) * (symbolsize + 1));
	symbol = strtok(buf, delim);
	while (symbol)
	{
		symbols[index] = stringdupicates(symbol);
		if (symbols[index] == NULL)
		{
			free(symbols);
			return (NULL);
		}
		symbol = strtok(NULL, delim);
		index++;
	}
	symbols[index] = '\0';
	free(buf);
	return (symbols);
}
