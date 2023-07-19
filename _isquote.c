#include "ctype.h"

/**
 * _isquote - function checks if a char is a quote
 * @c: char var to check
 * Return: If c is a quote, return 1. 
 * else, return 0.
 */
bool _isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}
