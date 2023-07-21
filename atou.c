#include "builtins.h"

/**
 * atou - function to convert a string to an integer
 * @s: char to check
 * Return: int data type
 */
unsigned int atou(char *s)
{
	size_t i;
	unsigned int number = 0;
	unsigned int to_add;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (UINT_MAX / 10 < number)
			return (UINT_MAX);
		number *= 10;
		to_add = s[i] - '0';
		if (UINT_MAX - to_add < number)
			return (UINT_MAX);
		number += to_add;
	}
	return (number);
}
