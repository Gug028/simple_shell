#include "shell.h"
#include <string.h>

void handle_segfault(int signo __attribute__((unused)));

int ex_code = 0;

/**
 * main - entry point of the progrm
 * @ac: the number of command-line arguments
 * @av: an array of command-line arguments
 *
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *__attribute__ ((unused)) cmd1, *cmd_copy = NULL;
	char *argv[MAX_ARGS], *ar[MAX_ARGS];

	int __attribute__ ((unused)) num_arg, r, count = 0;
	signal(SIGSEGV, handle_segfault);
	do {
		count++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		cmd = read_command();
		if (cmd == NULL)
			exit(ex_code);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
			continue;
		remwspaces(cmd);
		cmd_copy = strdup(cmd);
		tokenize(cmd_copy, ar);
		tokenize(cmd, argv);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
		{
			free(cmd);
			free(cmd_copy);
			continue;
		}
		if (_strcmp(argv[0], "exit") == 0)
		{
			r = _1exit(ar[1], count, av[0], argv);
			free(cmd);
			free(cmd_copy);
			if (r == 500)
				continue;
			exit(r);
		}
		if (process_command(argv) == 0)
		{
		}
		else
			_exec(argv, av[0], count);
		free(cmd);
		free(cmd_copy);
	} while (1);
	return (0);
}

/**
 * wspace - check character space or tab
 * @s: character to be checked
 *
 * Return: 1 if successful or 0 if not
 */
int wspace(char s)
{
	if (s == ' ' || s == '\t')
		return (1);
	return (0);
}

/**
 * remwspaces - remove white spaces
 * @s: string to be checked
 */
void remwspaces(char *s)
{
	int length = _strlen(s);
	int m = 0, n = length - 1, o;
	int p, count, q;

	if (s == NULL)
		return;
	while (m < length && wspace(s[m]))
	{
		m++;
	}
	while (n >= m && wspace(s[n]))
	{
		n--;
	}
	o = 0;
	while (m <= n)
	{
		s[o++] = s[m++];
	}
	s[0] = '\0';
	p = 0;
	count = 0;
	for (q = 0; q <= n; q++)
	{
		if (s[q] != ' ')
		{
			s[p++] = s[q];
			count = 0;
		}
		else if (count == 0)
		{
			s[p++] = s[q];
			count++;
		}
	}
	s[p] = '\0';
}

/**
 * read_command - read user input from stdin
 *
 * Return: pointer to the input command string
 */
char *read_command(void)
{
	char *cmd1 = _getline();

	signal(SIGINT, handle_sigint);
	return (cmd1);
}

/**
 * handle_sigint - signal handler for SIGINT (Ctrl+C)
 * @signo: the signal number
 */
void handle_sigint(int signo __attribute__((unused)))
{
	write(1, "\n", 1);
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	exit(0);
}
