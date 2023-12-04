#include "main.h"

/**
 * getcommand - gets a cmd object from a command string
 * @command: command string
 * @env: process environment
 * Return: a cmd structure
 */
cmd *getcommand(const char *command, char ***env)
{
	cmd *res = NULL;
	char *pathname = NULL;

	if (command == NULL)
		return (NULL);
	res = find_builtin(command);
	if (res != NULL)
		return (res);
	if (is_path(command))
		pathname = copy(command);
	else
		pathname = find_in_PATH(command, *env);

	if (!can_access(command, pathname))
		return (NULL);

	res = make_execmd(pathname);
	return (res);
}
