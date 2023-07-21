#include "tokens.h"

/**
 * arrdup - function duplicates a NULL terminated array
 * @arr: array to duplicate
 *
 * Return: duplicate of array
 */
char **arrdup(char **arr)
{
	char **dup = NULL;
	size_t length = 0;

	if (!arr)
		return (NULL);
	while (arr[length++])
		;
	dup = malloc(sizeof(*dup) * length);
	if (!dup)
		return (NULL);
	while (length--)
		dup[length] = _strdup(arr[length]);
	return (dup);
}

