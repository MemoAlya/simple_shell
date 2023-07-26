#include "main.h"

/**
 * _memcpy - Function copies info between void ptrs.
 * @newptr: pointer to dest
 * @ptr: source ptr.
 * @size: size of new pointer.
 *
 * Return: nothing.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int j;

	for (j = 0; j < size; j++)
		char_newptr[j] = char_ptr[j];
}

/**
 * _realloc - function to reallocate a memory block.
 * @ptr: ptr to the mem previously allocated.
 * @old_size: size of the allocated space of ptr in bytes
 * @new_size: new size of the new memory block in bytes
 *
 * Return: ptr
 * if new_size == old_size, return ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newpr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newpr = malloc(new_size);
	if (newpr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newpr, ptr, new_size);
	else
		_memcpy(newpr, ptr, old_size);

	free(ptr);
	return (newpr);
}

/**
 * _reallocdp - function reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @old_size: size of the allocated space of ptr.
 * @new_size: new size of the new memory block.
 *
 * Return: ptr
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newpr;
	unsigned int j;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newpr = malloc(sizeof(char *) * new_size);
	if (newpr == NULL)
		return (NULL);

	for (j = 0; j < old_size; j++)
		newpr[j] = ptr[j];

	free(ptr);

	return (newpr);
}
