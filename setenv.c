#include "main.h"

/**
 * _setenv - set or add environment variable
 * @name: environnement variable's name
 * @value: environnement variable's value
 * @overwrite: don't change existing variables if zero
 *
 * Return: 0 on success, -1 otherwise.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	int	i, keylen = _strlen(name), found = 0;
	char	new[1024];
	char	*temp = NULL;

	for (i = 0; environ[i] != NULL && !found; i++)
	{
		if (_strncmp(name, environ[i], keylen) == 0 && environ[i][keylen] == '=')
		{
			found = 1;
			break;
		}
	}
	new[0] = '\0';
	_strcat(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	if (found && overwrite)
	{
		temp = environ[i];
		environ[i] = _strdup(new);
		free(temp);
		return (0);
	}
	if (!found)
	{
		environ = _realloc(environ, i * sizeof(char *), (i + 2) * sizeof(char *));
		temp = _strdup(new);
		if (!temp)
		{
			write_error("Allocation Failed\n");
			return (-1);
		}
		environ[i] = temp;
		environ[i + 1] = NULL;
	}
	return (0);
}
