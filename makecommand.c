#include "main.h"

/**
 * make_execommand - make an exec command structure
 * @pathname: path of the executable
 * Return: file_cmd structure
 */
cmd *make_execmd(char *pathname)
{
	file_cmd *file_temp;

	file_temp = malloc(sizeof(file_cmd));
	file_temp->type = EXE_FILE;
	file_temp->pathname = copy(pathname);

	return ((cmd *)file_temp);
}
