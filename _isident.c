#include "ctype.h"

/**
 * _isident - function checks if a char is a true identifier char
 * @c: char var to check
 * Return: 1 if c is an identifier char;.
 * else, return 0.
 */
bool _isident(int c)
{
	return (c == '_' || _isalnum(c));
}
