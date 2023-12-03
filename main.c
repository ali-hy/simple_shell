#include "main.h"

/**
 * main - Entry point
 * @ac: argument count
 * @argv: array of arguments
 * @env: array of environment variables "key=value"
 * Return: Always 0
 */
int main(int ac, char **argv, char **env)
{
	char **args = NULL;
	cmd *command = NULL;

	UNUSED(ac);

	while (1)
	{
		args = get_input(STDIN_FILENO);
		if (args == NULL)
			break;
		if (args[0] == NULL)
			continue;

		command = getcommand(args[0], argv, &env);
		exit_status(SET_VARIABLE, runcommand(command, args, &env));
		free(command);
	}

	putchar('\n');
	return (0);
}
