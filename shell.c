#include "main.h"

/**
 * main - Our shell entry point
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: Always 0
 */

int main(int ac __attribute__((unused)), char **av)
{
	char *line, *path;
	char **tokens_list;

	environ = dup_environ();
	write_program_name(av[0]);
	while (1)
	{
		signal(SIGINT, _sigint);
		line = prompt_command();
		if (!line)
			continue;
		tokens_list = split_str_to_arr(line);
		if (!tokens_list)
			continue;
		if (builtin_exec(tokens_list, line) || builtin_exec2(tokens_list)
				|| cd_exec(tokens_list))
		{
			free_all(line, tokens_list);
			continue;
		}
		if (!_strchr(tokens_list[0], '/'))
		{
			path = search_exec(tokens_list[0]);
			if (path)
			{
				free(tokens_list[0]);
				tokens_list[0] = path;
			}
			else
			{
				print_error(tokens_list, tokens_list[0], 0);
				free_all(line, tokens_list);
				continue;
			}
		}
		execute_command(tokens_list);
		free_all(line, tokens_list);
	}
	return (0);
}
