#include "ctype.h"

/**
 * _isnumber - function checks if a string consists only of digits
 * @s: ptr to string
 * Return: true or false
 */
bool _isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!_isdigit(*s++))
				return (false);
		}
		return (true);
	}
	return (false);
}
