#include "shell.h"

/**
 * _memcpy - copies memory from the source to destination
 * @dest: destination
 * @src: source
 * @n: size of memory to be copied
 * Return: memory of destination
 */
void *_memcpy(void *dest, void *src, size_t n)
{
	char *cdest = (char *)(dest);
	const char *csrc = (const char *)(src);
	size_t k = 0;

	while (k < n)
	{
		cdest[k] = csrc[k];
		k++;
	}
	return (dest);
}

/**
 * _realloc - realloc function
 * @ptr: old malloc pointer
 * @size: new size
 * Return: new ptr
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

/**
 * _strdup - strdup()
 * @s: string
 * Return: duplicate of s
 */
char *_strdup(char *s)
{
	size_t len = _strlen(s) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}
	_memcpy(new_str, s, len);
	return (new_str);
}

/**
 * _strcat - strcat()
 * @dest: destination string
 * @src: source string
 * Return: concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	char *p = dest;
	int k = 0, l = 0;

	while (dest[k] != '\0')
	{
		k++;
	}
	while (src[l] != '\0')
	{
		p[k] = src[l];
		k++;
		l++;
	}
	p[k] = '\0';
	return (p);
}

/**
 * _strchr - implementation of strchr
 * @str: the string to search
 * @character: the character to find
 * Return: pointer to the str
 */
char *_strchr(const char *str, int character)
{
	/*Loop through the str until char is found*/
	while (*str)
	{
		if (*str == character)
		{
			return ((char *)str);/*Return the address of the char*/
		}
		str++;
	}
	return (NULL);
}
