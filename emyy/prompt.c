#include "my_shell.h"

/**
 * generate_prompt - Generate the shell prompt
 * by lagsounemyy
 */


void generate_prompt(void)
{
	/*Check if reading from a terminal*/
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$", 1);
	}
}
