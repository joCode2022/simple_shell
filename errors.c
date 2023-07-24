#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @d: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char d)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (d != BUF_FLUSH)
		buf[i++] = d;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @d: The character to print
 * @fc: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char d, int fc)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fc, buf, i);
		i = 0;
	}
	if (d != BUF_FLUSH)
		buf[i++] = d;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fc: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fc)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fc);
	}
	return (i);
}

