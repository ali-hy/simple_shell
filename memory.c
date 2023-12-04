#include "main.h"

/**
 * _realloc - reallocates memory and attempts to change its size
 * @ptr: ptr to allocated memeory
 * @old_size: old size of buffer
 * @new_size: size of buffer after resize
 * Return: pointer to newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, smaller_size = old_size < new_size ? old_size : new_size;
	char *ptr_c = ptr, *res;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	res = malloc(new_size);
	if (res == NULL)
		return (NULL);

	if (ptr == NULL)
	{
		return (res);
	}
	else
	{
		for (i = 0; i < smaller_size; i++)
			res[i] = ptr_c[i];

		free(ptr);
	}

	return (res);
}
