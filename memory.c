#include "monty.h"

/**
 * _realloc - homemade stdlib::realloc()
 * @ptr: pointer to a dynamically allocated memory
 * @new_size: new size of the memory chunck
 *
 * Return: the newly allocated memory address or NULL if allocation failed or
 *						size == 0
 */
void *re_alloc(void *ptr, size_t new_size)
{
	void *new = NULL;

	if (!ptr)
	{
		new = malloc(new_size);
		if (!new)
			return (NULL);
	}
	else
	{
		if (!new_size)
			free(ptr);
		else
		{
			new = malloc(new_size);
			if (!new)
				return (NULL);
			memcpy(new, ptr, new_size);
			free(ptr);
		}
	}
	return (new);
}
