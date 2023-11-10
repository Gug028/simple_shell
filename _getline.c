#include "shell.h"

/**
 * _getline - read the input by user from Stdin
 *
 * Return: input
 */
char *_getline(void)
{
	int m = 0;
	ssize_t nread;
	char c = 0, *buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
	{
		return (NULL);
	}
	while (c != EOF && c != '\n')
	{
		nread = read(STDIN_FILENO, &c, 1);
		if (nread == 0 || nread == -1)
		{
			free(buffer);
			if (nread == 0)
				exit(ex_code);
			if (nread == -1)
				perror("Error: ");
		}
		buffer[m] = c;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (m + 1 >= BUFFER_SIZE)
		{
			buffer = _realloc(buffer, m + 1);
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
		m++;
	}
	buffer[m - 1] = '\0';
	remwspaces(buffer);
	hash_handler(buffer);
	return (buffer);
}

/**
 * hash_handler - handle hash character in input
 * @buff: input buffer
 */
void hash_handler(char *buff)
{
	int m = 0;

	while (buff[m] != '\0')
	{
		if (buff[m] == '#')
			buff[m] = '\0';
		m++;
	}
}
