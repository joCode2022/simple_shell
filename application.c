#include "holberton.h"

/**
 *application - application commands used by users
 *All rights reserved or owned by noiseworking
 *
 *@cmd:chain from pointers to commands
 *@cp: command
 * Return: 0
 */
void application(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		freesupplies(cmd);
		exit(98);
	}
	else
		wait(&status);
}
