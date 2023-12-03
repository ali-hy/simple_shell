#include "main.h"

/**
 * getcommand - gets a cmd object from a command string
 * @command: command string
 * @argv: arguments passed to the shell
 * @env: process environment
 * Return: a cmd structure
 */
cmd *getcommand(const char *command, char **argv, char ***env)
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

	if (pathname != NULL)
	{
		if (access(pathname, F_OK) != 0)
		{
			print_err(argv, command, "not found");
			exit_status(SET_VARIABLE, 127);
			return (NULL);
		}
		if (access(pathname, X_OK) != 0)
		{
			print_err(argv, command, "Permission denied");
			exit_status(SET_VARIABLE, 127);
			return (NULL);
		}
		if (is_dir(pathname))
		{
			print_err(argv, command, "Permission denied");
			exit_status(SET_VARIABLE, 127);
			return (NULL);
		}
	}
	else
		print_err(argv, command, "not found");
	res = make_execmd(pathname);
	return (res);
}
