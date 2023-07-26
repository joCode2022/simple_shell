#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <sys/types.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

/* free efficiency for assistant function */
void freesupplies(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

/* my list strings */
int stringcompares(char *s1, char *s2);
int stringlength(char *s);
int stringncmp(char *s1, char *s2, int n);
char *stringdupicates(char *s);
char *stringcharacter(char *s, char c);

void application(char *cp, char **cmd);
char *findlocatepath(void);

/* built-in plugins */
int mytchecker(char **cmd, char *buf);
void userimmediate(void);
void signalhandler(int m);
char **distinct_symbol(char *line);
char *pathtesting(char **path, char *command);
char *pathend(char *path, char *command);
int builtihandler(char **command, char *line);
void leavecommand(char **command, char *line);

void environmentprint(void);

/* variables env */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#endif
