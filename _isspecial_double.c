#include "quote.h"

/**
 * _isspecial_double - funct to check if a char is special inside double quotes
 * @c: the char var to check
 * Return: 1 if c is special, 
 * else, return 0.
 */
int _isspecial_double(char c)
{
	return (c == '"' || c == '$' || c == '\\');
}
