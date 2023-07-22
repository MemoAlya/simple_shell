#include "string.h"

/**
 * _strchr - Find the index of the first occurrence of a character in a string.
 * @str: The string to search.
 * @chr: The character to find.
 * Return: The index of the first occurrence of chr, or -1 if not found.
 */
ssize_t _strchr(const char *str, char chr)
{
    if (!str)
        return -1;

    for (ssize_t index = 0; str[index]; ++index)
    {
        if (str[index] == chr)
            return index;
    }

    return -1;
}

/**
 * _strdup - Create a duplicate of a string.
 * @str: The string to duplicate.
 * Return: A pointer to the newly allocated duplicate string, or NULL on failure.
 */
char *_strdup(const char *str)
{
    if (!str)
        return NULL;

    size_t size = _strlen(str) + 1;
    char *dup = malloc(size);
    if (!dup)
        return NULL;

    return _strcpy(dup, str);
}

/**
 * _strlen - Calculate the length of a string.
 * @str: The string to calculate the length of.
 * Return: The length of the string.
 */
ssize_t _strlen(const char *str)
{
    if (!str)
        return -1;

    const char *pos = str;
    while (*pos)
        ++pos;

    return pos - str;
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if s1 matches s2, a positive value if s1 is greater than s2,
 *         and a negative value if s1 is less than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    for (; *s1 && *s2; ++s1, ++s2)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
    }

    return *s1 - *s2;
}

/**
 * _strcpy - Copy a string from source to destination.
 * @dest: Destination buffer.
 * @src: Source string.
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
    char *pos = dest;

    while ((*pos++ = *src++))
        ;

    return dest;
}

