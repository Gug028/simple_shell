#include "shell.h"

/**
 * cd - changing the directory
 * @path: the path to change to
 *
 * Return: 0 on success, 1 on failure
 */
void cd(char *path)
{
	char *home = _getenv("HOME");
	char *oldpwd = _getenv("OLDPWD");
	char *pwd = _getenv("PWD");
	char cwd[1024];

	if (path == NULL)
	{
		if (chdir(home) == -1)
		{
			perror("cd");
			return;
		}
		setenv("OLDPWD", pwd, 1);
		setenv("pwd", home, 1);
	}
	else if (_strcmp(path, "-") == 0)
	{
		if (oldpwd != NULL)
		{
			if (chdir(oldpwd) == -1)
			{
				perror("cd");
				return;
			}
			setenv("OLDPWD", pwd, 1);
			setenv("pwd", oldpwd, 1);
		}
	}
	else
	{
		if (chdir(path) == -1)
		{
			perror("cd");
			return;
		}
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", cwd, 1);
	}
}
