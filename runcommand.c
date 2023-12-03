#include "main.h"

/**
 * runcommand - runs a command
 * @command: command to run
 * @args: args for this command
 * @env: program's env
 * Return: 0 on success, exit code on fail
 */
int runcommand(cmd *command, char **args, char ***env)
{
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
		return (run_exe(file_temp, args, *env));

	case BUILTIN:
		builtin_temp = (builtin_cmd *)command;
		return (run_builtin(builtin_temp, args, env));

	default:
		break;
	}

	return (0);
}

/**
 * run_exe - run an executable file
 * @command: command details
 * @args: arguments to pass to the command
 * @env: environment of the program
 * Return: exit status
 */
int run_exe(file_cmd *command, char **args, char **env)
{
	int res;

	if (fork() == 0)
	{
		res = execve(command->pathname, args, env);
		if (res == -1)
			exit(1);
	}

	wait(&res);
	return (res);
}

/**
 * run_builtin - run a builtin command
 * @command: builtin command structure
 * @args: array of args passed to builtin
 * @env: pointer to process environment
 * Return: exit code
 */
int run_builtin(builtin_cmd *command, char **args, char ***env)
{
	return (command->builtin_func(args, env));
}
