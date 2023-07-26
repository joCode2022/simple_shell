#include "main.h"

/**
 * _sigint - signal handler for the SIGINT signal
 * @r: integer
 */

void	_sigint(int r __attribute__((unused)))
{
	write(STDERR_FILENO, "\n#cisfun$ ", _strlen("\n#cisfun$ "));
}
