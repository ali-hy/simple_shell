#include "main.h"

/**
 * get_in_fd - gets the file directory of the passed script file
 * @filename: name of the script file
 * Return: the file directory int; else exits with error
 */
int get_in_fd(char *filename)
{
	int fd = STDIN_FILENO;
	char *temp;

	if (filename == NULL)
	{
		fd = STDIN_FILENO;
	}
	else
	{
		temp = concat("Cannot open ", filename);
		if (access(filename, F_OK) == -1)
		{
			print_err(temp, "No such file");
			free(temp);
			exit(2);
		}

		if (access(filename, R_OK) == -1)
		{
			print_err(temp, "Permission Denied");
			free(temp);
			exit(2);
		}

		fd = open(filename, O_RDONLY);

		if (fd == -1)
		{
			print_err(temp, "Unknown error");
			free(temp);
			exit(2);
		}
		free(temp);
	}

	return (fd);
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
			temp = _realloc(*line_ptr, *n, *n + IN_BUFFER_SIZE);
			*line_ptr = temp;
			*n += IN_BUFFER_SIZE;
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
 * @temp: string to be freed after split
 * Return: length of input
 */
char **get_input(int fd, char **temp)
{
	char **res = NULL, *line = NULL;
	int getline_status = 0;
	int line_len = 0;

	if (isatty(fd))
		write(STDOUT_FILENO, "$ ", 2);

	getline_status = get_line(&line, &line_len, fd);

	if (getline_status == -1)
	{
		free(line);
		return (NULL);
	}

	res = split(line, " \n", temp);

	free(line);
	return (res);
}
