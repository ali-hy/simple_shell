#include "main.h"

/**
 * runcommand - runs a command
 * @command: command to run
 * @args: args for this command
 * Return: 0 on success, exit code on fail
 */
int runcommand(cmd *command, char **args)
{
	int res;
	file_cmd *file_temp = NULL;
	builtin_cmd *builtin_temp = NULL;
	multi_cmd *multi_temp = NULL;

	UNUSED(builtin_temp);
	UNUSED(multi_temp);

	if (command == NULL)
		return (0);

	switch (command->type)
	{
	case EXE_FILE:
		file_temp = (file_cmd *)command;
		res = run_exe(file_temp, args);
		free(file_temp->pathname);
		break;

	case BUILTIN:
		builtin_temp = (builtin_cmd *)command;
		res = run_builtin(builtin_temp, args);
		break;

	default:
		res = 1;
		break;
	}

	return (res);
}

/**
 * run_exe - run an executable file
 * @command: command details
 * @args: arguments to pass to the command
 * Return: exit status
 */
int run_exe(file_cmd *command, char **args)
{
	int res = 0;

	if (fork() == 0)
	{
		res = execve(command->pathname, args, _env(GET_VARIABLE, NULL));
		if (res == -1)
			exit(1);
	}

	wait(&res);
	res = WEXITSTATUS(res);
	return (res);
}

/**
 * run_builtin - run a builtin command
 * @command: builtin command structure
 * @args: array of args passed to builtin
 * Return: exit code
 */
int run_builtin(builtin_cmd *command, char **args)
{
	return (command->builtin_func(args));
}
