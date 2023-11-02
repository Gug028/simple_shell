#ifndef SHELL_H
#define SHELL_H

/* Headers */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <signal.h>

/* Macros */
#define BUFFER_SIZE 5024
#define MAX_ARGS 1024
#define MAX_NUM_Aliases 100
#define UNUSED __attribute__((unused))

static char *cmd __attribute__((unused));
extern char **environ UNUSED;
extern int ex_code;

/* Function Prototypes */
char *_getline(void);
char *read_command(void);
void hash_handler(char *buff);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
int _strncpy(char *dest, char *src, int size);
void *_memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, size_t size);
char *which(char *command);
char *_strtok(char *str, char const *delim);
char *_getenv(char *str);
int _strncmp(const char *str1, const char *str2, size_t len);
int _strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(char *s);
void remove_trailing_and_leading_spaces(char *str);
void tokenize(char *command, char *argv[MAX_ARGS]);
int num_args(char *argv[]);
void _exec(char **_argum, char *av, int count);
int _1exit(char *status __attribute__((unused)), int c, char *a, char **ag);
int _atoi(const char *str);
void cd(char *path);
int process_command(char **argv);

/**
 * struct Node - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 */
struct Node
{
	char *str;
	struct Node *next;
};

static struct Node *new_node(char *str) UNUSED;
/**
 * new_node - creates a new node for a linked list
 * @str: string value to be stores in the new node
 * Return: pointer to the newly created node
 */
static struct Node *new_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);
	node->str = str;
	node->next = NULL;
	return (node);
}

static void add_node(struct Node **head, struct Node *node) UNUSED;
/**
 * add_node - adds a node to the end of a linked list
 * @head: pointer to the head of the linked list
 * @node: node to be added to the linked list
 */
static void add_node(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node *current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

void print_list(struct Node *head);
void free_list(struct Node *head);
int _env(void);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value);
void add_env_var(struct Node **head, const char *name, const char *value);
void update_environ(struct Node *head);
void handle_sigint(int signo __attribute__((unused)));
void remwspaces(char *s);
int wspace(char s);

/**
 * struct alias_s - a structure representing an alias
 * @name: the name of the alias
 * @value: the value of the alias
 * @next: a pointer to the next alias in the linked list
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;
void init_aliases(alias_t **aliases);
int alias_command(char *argv[MAX_ARGS], int num_arg __attribute__((unused)));
char *_strchr(const char *str, int character);
void print_alias(alias_t, *alias);
void set_alias(alias_t **aliases, char *name, char *value);
void print_all_aliases(alias_t *aliases);
void _execve(char *c, char **p, char **r);
void _perror(char *err, int count, char *c);
void _print(char *s);
void _pnumber(int n);
int _putchar(char c);
int access_check(char **arg, char *cmd, char *err, int c, char **e);
void _perrore(char *err, int count, char *c, char *arg);

#endif /* SHELL_H */
