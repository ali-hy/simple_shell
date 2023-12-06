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

/**
 * my_free - frees a memory block and sets it to null, only if it's not null
 * @ptr: pointer to a pointer that points to the memory block
 * Return: 1 if freed, 0 if not freed
 */
int my_free(void **ptr)
{
	if (*ptr == NULL)
		return (0);

	free(*ptr);
	*ptr = NULL;
	return (1);
}
