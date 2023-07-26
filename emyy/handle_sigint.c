#include "my_shell.h"

/**
 * handle_sigint - Signal handler for SIGINT
 * credit to lagsoun emyy
 * @signum: The signal number
 */

void handle_sigint(__attribute__((unused))int signum)
{

    write(STDOUT_FILENO, "\n$ ", 3);
    fflush(stdout);
}
