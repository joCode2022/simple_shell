#include "my_shell.h"

/**
 * handle_builtin_cmvd - Handle a built-in command
 * @command: The built-in command to handle
 * @argv: The program name and arguments
 * by lagsimane
 */

void handle_builtin_cmvd(const char *command, char **argv)
{
    if (strcmp(command, "exit") == 0)
    {
        should_exit = 1;
    }
    else if (strcmp(command, "cd") == 0)
    {
        handle_cd(argv);
    }
}
