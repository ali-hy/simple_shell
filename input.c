#include "main.h"

/**
 * push - push a pointer into an array of pointers
 * @arr: pointer to array of pointers
 * @length: pointer to length of current array
 * @ptr: pointer to push to array
 * Return: 1 on success, 0 on failure
 */
int push(void ***arr, size_t *length, void *ptr)
{
	void **curr = *arr,
		 **res = malloc((*length + 1) * sizeof(void *));
	size_t i;

	for (i = 0; i < *length; i++)
		res[i] = curr[i];

	res[i] = ptr;
	if (curr)
		free(curr);

	(*length)++;
	*arr = res;
	return (1);
}

/**
 * get_input - get resolved line of input
 * @fd: file descriptor of the file to read from
 * Return: length of input
 */
char **get_input(int fd)
{
	char **res = NULL, *line = NULL, *temp = NULL;
	int getline_status = 0;
	size_t line_len = 0;

	if (isatty(fd))
		write(STDOUT_FILENO, "$ ", 2);

	getline_status = getline(&temp, &line_len, stdin);

	if (getline_status == -1)
	{
		free(temp);
		return (NULL);
	}

	line = copy(temp);
	free(temp);

	res = split(line, " \n");

	return (res);
}
