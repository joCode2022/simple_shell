#include "holberton.h"
/**
* main - he does the reading
* All rights reserved or owned by noiseworking
*
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: nothing 0
*/

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, signalhandler);
	while (1)
	{
		freesupplies(command);
		freesupplies(paths);
		free(pathcommand);
		userimmediate();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = distinct_symbol(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (mytchecker(command, line))
			continue;
		path = findlocatepath();
		paths = distinct_symbol(path);
		pathcommand = pathtesting(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			application(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
