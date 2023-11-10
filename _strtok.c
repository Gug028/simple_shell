#include "shell.h"

/**
 * _strtok - strtok implementation
 * @str: the string
 * @delim: the delimiter
 *
 * Return: token
 */
char *_strtok(char *str, char const *delim)
{
	static char *ptr;
	int size = 0;
	char *token;
	int m = 0;

	if (str != NULL)
		ptr = str;
	while (ptr[m] != '\0')
		if (ptr[m] == *delim)
		{
			ptr[m] = '\0';
			token = ptr;
			ptr = &ptr[m + 1];
			return (token);
		}
		else
			m++;
	if (ptr[0] != '\0')
	{
		while (ptr[size] != 0)
			size++;
		token = ptr;
		ptr += size; /* update ptr to '\0' */
		return (token);
	}
	return (NULL);
}
