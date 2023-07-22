#include "string.h"
#include <stdlib.h>

/**
 * _strnchr - Find the index of the first occurrence of a character in a string.
 * @str: The input string to search.
 * @chr: The character to find.
 * @n: The maximum number of characters to check.
 *
 * Return: The index of the first occurrence of 'chr' in 'str', or -1 if 'chr' is not found.
 */
ssize_t _strnchr(const char *str, char chr, size_t n)
{
    if (!str)
        return -1;

    for (size_t i = 0; i < n && str[i]; ++i)
    {
        if (str[i] == chr)
            return i;
    }

    return -1;
}

/**
 * _strndup - Duplicate a portion of the given string.
 * @str: The string to duplicate.
 * @n: The maximum number of bytes to copy.
 *
 * Description: This function duplicates at most 'n' bytes from 'str'.
 * If 'str' is longer than 'n', only 'n' bytes are copied, and a terminating null byte is added.
 *
 * Return: If 'str' is NULL or if memory allocation fails, return NULL.
 * Otherwise, return a pointer to the dynamically-allocated duplicate.
 */
char *_strndup(const char *str, size_t n)
{
    if (!str)
        return NULL;

    size_t len = 0;
    while (n && str[len])
    {
        --n;
        ++len;
    }

    char *dup = malloc(sizeof(char) * (len + 1));
    if (!dup)
        return NULL;

    for (size_t i = 0; i < len; ++i)
        dup[i] = str[i];
    dup[len] = '\0';

    return dup;
}

/**
 * _strnlen - Calculate the length of a string, up to a specified number of characters.
 * @str: The string to measure.
 * @n: The maximum number of characters to check.
 *
 * Return: The lesser of 'n' and the actual length of the string (excluding the null terminator).
 */
ssize_t _strnlen(const char *str, size_t n)
{
    if (!str)
        return -1;

    const char *pos = str;
    while (n && *pos)
    {
        --n;
        ++pos;
    }

    return pos - str;
}

/**
 * _strncmp - Compare two strings up to a specified number of bytes.
 * @s1: A string to compare.
 * @s2: The other string to compare.
 * @n: The maximum number of bytes to compare.
 *
 * Return: 0 if the first 'n' bytes of 's1' match the first 'n' bytes of 's2',
 * a negative integer if 's1' is less than 's2',
 * a positive integer if 's1' is greater than 's2'.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n && *s1 && *s2; ++i, ++s1, ++s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
    }

    if (n && *s1)
        return 1;
    if (n && *s2)
        return -1;

    return 0;
}

/**
 * _strncpy - Copy a portion of the source string to the destination buffer.
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The maximum number of bytes to copy.
 *
 * Description: This function copies at most 'n' bytes from 'src' to 'dest'.
 * If the length of 'src' is less than 'n', the remaining bytes in 'dest' are filled with null bytes.
 *
 * Return: A pointer to 'dest'.
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
    char *pos = dest;
    for (size_t i = 0; i < n && *src; ++i, ++src, ++pos)
        *pos = *src;
    
    for (size_t i = n; i > 0 && *pos; --i, ++pos)
        *pos = '\0';

    return dest;
}

