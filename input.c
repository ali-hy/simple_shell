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
 * get_line - get a new line
 * @line_ptr: pointer to string that will hold lin
 * @n: pointer to max size to read
 * @fd: file descriptor for the stream to read from
 * Return: 1 on success, -1 on failure
 */
int get_line(char **line_ptr, int *n, int fd)
{
	static char buffer[IN_BUFFER_SIZE];
	static int read_size, i, prev_fd = -1;
	int j = 0, found_newline = 0;
	char *temp = NULL;

	if (fd != prev_fd)
	{
		prev_fd = fd;
		read_size = 0;
		i = 0;
	}

	while (!found_newline)
	{
		if (j >= *n)
		{
			temp = _realloc(*line_ptr, *n, *n + 128);
			if (*line_ptr != NULL)
				free(*line_ptr);
			*line_ptr = temp;
			*n += 128;
		}
		if (i >= read_size)
		{
			read_size = read(fd, buffer, IN_BUFFER_SIZE);
			if (read_size == 0)
				return (-1);
			i = 0;
		}
		while (i < read_size)
		{
			if (buffer[i] == '\n')
				found_newline = 1;

			(*line_ptr)[j] = buffer[i];

			j++, i++;
			if (found_newline)
				break;
		}
	}

	(*line_ptr)[j] = '\0';

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
	int line_len = 0;

	if (isatty(fd))
		write(STDOUT_FILENO, "$ ", 2);

	getline_status = get_line(&temp, &line_len, STDIN_FILENO);

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
