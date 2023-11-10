#include "shell.h"

/**
 * _exec - execute the command
 * @_argum: array of arguments
 * @av: name of the program
 * @count: count of command
 */
void _exec(char **_argum, char *av, int count)
{
	char *cmd1;
	/*char *envp[] = {"TERM=xterm-256color", NULL};*/
	char err[50];
	int status;

	_strcpy(err, av);
	ex_code = 0;
	if (_argum[0][0] == '/')
	{
		if (access_check(_argum, NULL, err, count, environ))
			return;
	}
	else
	{
		if (_argum[0][0] != '.')
		{
			cmd1 = which(_argum[0]);
			if (cmd1 == NULL)
			{
				_perror(err, count, _argum[0]);
				return;
			}
			if (access_check(_argum, cmd1, err, count, environ))
				return;
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		ex_code = (WEXITSTATUS(status));
	}
}

/**
 * _execve - runs error code and exec
 * @c: command prompt
 * @p: arguments to command
 * @r: environment variable
 */
void _execve(char *c, char **p, char **r)
{
	if ((execve(c, p, r) == -1))
		ex_code = 127;
	ex_code = 1;
}

/**
 * _perror - printing error and checking exit code
 * @err: error string
 * @count: number of command
 * @c: name of the file
 */
void _perror(char *err, int count, char *c)
{
	ex_code = 127;
	_print(err);
	_print(": ");
	_pnumber(count);
	_print(": ");
	_print(c);
	_print(": not found\n");
}

/**
 * _print - prints a character
 * @s: string input
 */
void _print(char *s)
{
	int n = 0;

	while (s[n] != '\0')
	{
		_putchar(s[n]);
		n++;
	}
}

/**
 * _pnumber - print the correct number
 * @n: the integer
 */
void _pnumber(int n)
{
	int first = n, count = 0, x = 1, i, tmp;

	tmp = n;

	if (n < 0)
	{
		_putchar('-');
		n = (n * -1) - 1;
	}
	while (first != 0)
	{
		first = first / 10;
		count++;
	}
	while (x <= count)
	{
		first = n;
		i = x;
		while (i < count)
		{
			first = first / 10;
			i++;
		}
		if (tmp < 0 && x == count)
			_putchar(((first % 10) + 48) + 1);
		else
			_putchar((first % 10) + 48);
		x++;
	}
	if (count == 0)
		_putchar('0');
}
