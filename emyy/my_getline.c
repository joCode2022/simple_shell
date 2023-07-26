#include "my_shell.h"
/**
 * my_getline -  GEts inputs
 * Return: The input.
 */


char *my_getline(void)
{
	int tmp;
	char *lptr = NULL;
	size_t n = 0;

	tmp = getline(&lptr, &n, stdin);
	if (tmp == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(0);
	}
	return (lptr);
}
