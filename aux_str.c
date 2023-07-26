#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *dest, const char *src)
{
	int a;
	int j;

	for (a = 0; dest[a] != '\0'; a++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[a] = src[j];
		a++;
	}

	dest[a] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - Function compares two strings.
 * @s1: 1st comp
 * @s2: 2nd compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0; s1[j] == s2[j] && s1[j]; j++)
		;

	if (s1[j] > s2[j])
		return (1);
	if (s1[j] < s2[j])
		return (-1);
	return (0);
}
/**
 * _strchr - function locates a character in a string,
 * @s: string par
 * @c: char par
 * Return: the ptr to the first occurrence of the char.
 */
char *_strchr(char *s, char c)
{
	unsigned int j = 0;

	for (; *(s + j) != '\0'; j++)
		if (*(s + j) == c)
			return (s + j);
	if (*(s + j) == c)
		return (s + j);
	return ('\0');
}
/**
 * _strspn - Function gets the length of a prefix substring.
 * @s: initial seg.
 * @accept: accept bytes.
 * Return: the num of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int a, j, bool;

	for (a = 0; *(s + a) != '\0'; a++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + a) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (a);
}
