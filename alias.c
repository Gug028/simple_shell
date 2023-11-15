#include "shell.h"

/**
 * init_aliases - initializes the aliases with some standard values
 * @aliases: head of the linked list of aliases
 */
void init_aliases(alias_t **aliases)
{
	set_alias(aliases, "l", "ls -CF");
	set_alias(aliases, "la", "ls -A");
	set_alias(aliases, "ll", "ls -alF");
	set_alias(aliases, "ls", "ls --color=auto");
}

/**
 * alias_command - the alias command
 * @argv: the argument
 * @num_arg: number of arguments
 * Return: 0 if successful
 */
int alias_command(char *argv[MAX_ARGS], int num_arg __attribute__((unused)))
{
	static alias_t *aliases;
	static int initialized;
	int m;
	char *name, *value;
	alias_t *alias;

	if (initialized)
	{
		init_aliases(&aliases);
		initialized = 1;
	}
	if (_strcmp(argv[0], "alias") != 0)
		return (0);
	if (num_arg == 1)
	{
		for (alias = aliases; alias; alias = alias->next)
			print_alias(alias);
		return (1);
	}
	for (m = 1; m < num_arg; m++)
	{
		name = argv[m];
		value = _strchr(argv[m], '=');
		if (value)
		{
			*value = '\0';/*replaces '=' by '\0'*/
			value++;
			if (*value == '\0')
				continue;
			set_alias(&aliases, name, value);
		}
		else
		{
			print_all_aliases(aliases);
		}
	}
	return (1);
}

/**
 * set_alias - sets an alias
 * @aliases: head of the linked list of aliases
 * @name: name of the alias
 * @value: value of the alias
 */
void set_alias(alias_t **aliases, char *name, char *value)
{
	alias_t *alias;

	for (alias = *aliases; alias; alias = alias->next)
		if (_strcmp(alias->name, name) == 0)
			break;
	if (alias)
	{
		free(alias->value);
		alias->value = _strdup(value);
	}
	else
	{
		alias = malloc(sizeof(*alias));
		if (!alias)
			return;
		alias->name = _strdup(name);
		alias->value = _strdup(value);
		alias->next = *aliases;
		*aliases = alias;
	}
	free(alias);
}

/**
 * print_alias - prints an alias
 * @alias: the alias to be printed
 */
void print_alias(alias_t *alias)
{
	if (alias->value[0] != '\'')
	{
		write(1, "alias ", 6);
		write(1, alias->name, _strlen(alias->name));
		write(1, "='", 2);
		write(1, alias->value, _strlen(alias->value));
		write(1, "'\n", 2);
	}
	else
	{
		write(1, "alias ", 6);
		write(1, alias->name, _strlen(alias->name));
		write(1, "=", 1);
		write(1, alias->value, _strlen(alias->value));
		write(1, "\n", 1);
	}
}
