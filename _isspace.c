#include "ctype.h"

/**
 * _isspace - funct checks if a char is a whitespace
 * @c: the char var to check
 * Return: 1 if c is whitespace, 
 * else, return 0.
 */
bool _isspace(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}
