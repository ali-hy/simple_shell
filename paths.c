#include "main.h"

/**
 * is_path - check if a command is a path
 * @command: command to check
 * Return: 1 if command is a path, 0 if it isn't
 */
int is_path(const char *command)
{
	int res = starts_with(command, "../");

	res = res || starts_with(command, "./");
	res = res || starts_with(command, "/");

	return (res);
}

/**
 * path_concat - put two strings together to make a path
 * @s1: first part of path
 * @s2: second part of path
 * Return: result of both
 */
char *path_concat(const char *s1, const char *s2)
{
	int i, l1 = len(s1), l2 = len(s2), add_separator = 0;
	int l_res = l1 + l2;
	char *res;

	if (s1 == NULL)
		return (copy(s2));

	if (s2 == NULL)
		return (copy(s1));

	if (s1[l1 - 1] != '/')
		add_separator = 1;

	l_res += add_separator;
	res = malloc(l_res + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; i < l1; i++)
		res[i] = s1[i];

	if (add_separator)
		res[i] = '/';

	i++;
	for (; i < l_res; i++)
	{
		res[i] = s2[i - l1 - add_separator];
	}

	res[i] = '\0';
	return (res);
}

/**
 * is_dir - check if a pathname is a directory
 * @pathname: ...
 * Return: 1 if true, 0 if false
 */
int is_dir(const char *pathname)
{
	struct stat file_stat;

	stat(pathname, &file_stat);
	return (S_ISDIR(file_stat.st_mode));
}

/**
 * find_in_PATH - finds a file in PATH
 * @command: command with the file name
 * @env: process environment
 * Return: a string of the pathname if found, NULL if not found
 */
char *find_in_PATH(const char *command, char **env)
{
	char *PATH, **paths, *pathname;
	int i;

	PATH = env[get_env("PATH", env)];

	/* get start of the PATH value */
	while (*PATH != '=')
		PATH++;
	PATH++;

	paths = split(PATH, ":");

	for (i = 0; paths[i] != NULL; i++)
	{
		pathname = path_concat(paths[i], command);
		if (access(pathname, F_OK) == 0)
		{
			return (pathname);
		}
		free(pathname);
	}

	return (NULL);
}
