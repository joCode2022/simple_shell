#include "my_shell.h"


/**
 * cmd_exiter - handles the exit command
 * @cmvd: tokenized command
 * @str: input read from stdin
 *
 * This function frees the allocated memory and exits the program.
 */
void cmd_exiter(char **cmvd, char *str)
{
free(str);
buff_free(cmvd);
exit(0);
}

#include "my_shell.h"

/**
 * execute - executes a command
 * @cp: command path
 * @cmd: vector array of command arguments
 *
 * This function forks a new process and executes the command.
 * It waits for the child process to complete before returning.
 */
void execute(char *cp, char **cmd)
{
pid_t _pid;
int token;
char **env = environ;

_pid = fork();
if (_pid < 0)
{
perror(cp);
}
if (_pid == 0)
{
execve(cp, cmd, env);
perror(cp);
free(cp);
buff_free(cmd);
exit(98);
}
else
wait(&token);
}

#include "my_shell.h"
/**
 * check - checks whether it is a built-in function
 * @cmvd: tokenized user input
 * @token: line derived from getline function
 *
 * This function checks if the command is a built-in function.
 * If it is, the corresponding built-in handler is called.
 * If not, it checks if the command starts with '/' and executes it if true.
 *
 * Return: 1 on success, 0 on failure
 */
int check(char **cmvd, char *token)
{
if (built_handler(cmvd, token))
return (1);
else if (**cmvd == '/')
{
execute(cmvd[0], cmvd);
return (1);
}
return (0);
}

#include "my_shell.h"

/**
 * path_adder - adds path to command
 * @path: path of the command
 * @cmvd: user-entered command
 *
 * This function concatenates the path and command, adding a '/' if necessary.
 *
 * Return: buffer containing the concatenated path and command
 * NULL if memory allocation failed
 */
char *path_adder(char *path, char *cmvd)
{
char *buffer;
size_t a = 0, b = 0;

if (cmvd == 0)
cmvd = "";

if (path == 0)
path = "";

buffer = malloc(sizeof(char) * (strlen(path) + strlen(cmvd) + 2));
if (!buffer)
return (NULL);

while (path[a])
{
buffer[a] = path[a];
a++;
}

if (path[a - 1] != '/')
{
buffer[a] = '/';
a++;
}
while (cmvd[b])
{
buffer[a + b] = cmvd[b];
b++;
}
buffer[a + b] = '\0';
return (buffer);
}
