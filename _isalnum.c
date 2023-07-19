#include "ctype.h"

/**
 * _isalnum - function checks if char varaiable is alphanumeric
 * @c: char var to check
 * Return: If c is alphanumeric, return 1.
 * else, return 0.
 */
bool _isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}
