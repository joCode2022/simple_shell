#include "my_shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @token: The name of the environment variable to retrieve
 *
 * Return: The value of the environment variable if found, NULL otherwise
 */

char *_getenv(const char *token)
{
	size_t token_length = strlen(token);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(token, *env, token_length) == 0 && (*env)[token_length] == '=')
	{
		return (&(*env)[token_length + 1]);
	}
	}

	return (NULL);
}

