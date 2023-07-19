#include "ctype.h"

/**
 * _isalpha - function to check if a char is alphabetic
 * @c: char var to check
 * Return: 1 if it is alphabetic. 
 * else, return 0.
 */
bool _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
