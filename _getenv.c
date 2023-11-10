# include "shell.h"

/**
 * _getenv - getenv()
 * @str: string
 * Return: path
 */
char *_getenv(char *str)
{
	int n = 0;
	int len = _strlen(str);

	while (environ[n] != NULL)
	{
		if (_strncmp(environ[n], str, len) == 0 && environ[n][len] == 's')
		{
			return (&(environ[n][len + 1]));
		}
		n++;
	}
	return (NULL);
}
