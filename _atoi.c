#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @infos: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *infos)
{
	return (isatty(STDIN_FILENO) && infos->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @d: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @d: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @sq: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *sq)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; sq[i] != '\0' && flag != 2; i++)
	{
		if (sq[i] == '-')
			sign *= -1;

		if (sq[i] >= '0' && sq[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (sq[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

