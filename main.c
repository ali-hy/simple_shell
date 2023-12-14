#include "main.h"

/**
 * should_exit - check if program should exit, as well as free
 * any memroy blocks that need freeing if program will exit
 * @command: command entered into the program
 * @exit_code: exit code from running command
 * Return: 1 if program should exit, 0 if it shouldn't
 */
int should_exit(cmd *command, int exit_code)
{
	if (command != NULL)
	{
		if (command->type == BUILTIN)
			if (((builtin_cmd *)command)->builtin_func == exit_builtin)
				if (exit_code == -1)
				{
					free(command);
					return (1);
				}
		exit_status(SET_VARIABLE, exit_code);
		free(command);
	}

	return (0);
}

/**
 * main - Entry point
 * @ac: argument count
 * @argv: array of arguments
 * @env: array of environment variables "key=value"
 * Return: Always 0
 */
int main(int ac, char **argv, char **env)
{
	char **args = NULL, *temp1 = NULL, *temp2 = NULL;
	cmd *command = NULL;
	int exit_code = 0, in_fd;

	init_program(ac, argv, env);
	in_fd = get_in_fd(argv[1]);

	while (1)
	{
		args = get_input(in_fd, &temp1);
		if (args == NULL)
			break;
		if (args[0] == NULL)
		{
			free(temp1);
			free(args);
			continue;
		}
		command = getcommand(args[0], &temp2);
		if (command != NULL)
			exit_code = runcommand(command, args);
		my_free((void **)&temp1);
		my_free((void **)&temp2);
		free(args);
		if (should_exit(command, exit_code))
			break;
	}
	free_env_end();
	if (isatty(in_fd) && exit_code != -1)
		put_c('\n');
	close(in_fd);
	return (exit_status(GET_VARIABLE, 0));
}
