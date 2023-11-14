#include "shell.h"

/**
 * access_check - checks file access
 * @arg: command arg
 * @cmd: command arg
 * @err: error string
 * @c: count of command
 * @e: environment variable
 *
 * Return: 0 if success, 1 otherwise
 */
int access_check(char **arg, char *cmd, char *err, int c, char **e)
{
	pid_t idcheck;
	char *p = NULL;

	p = (cmd == NULL) ? arg[0] : cmd;
	if (access(p, X_OK) == 0)
	{
		idcheck = fork();
		if (idcheck == 0)
		{
			_execve(p, arg, e);
		}
		return (0);
	}
	else
	{
		_perror(err, c, p);
		return (1);
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
