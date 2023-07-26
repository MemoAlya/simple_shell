
#include "main.h"

/**
 * rev_string - function reverses a string.
 * @s: input str.
 * Return: nothing.
 */
void rev_string(char *s)
{
	int cou = 0, i, j;
	char *string, temp;

	while (cou >= 0)
	{
		if (s[cou] == '\0')
			break;
		cou++;
	}
	string = s;

	for (i = 0; i < (cou - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(string + j);
			*(string + j) = *(string + (j - 1));
			*(string + (j - 1)) = temp;
		}
	}
}

