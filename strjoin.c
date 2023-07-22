#include "string.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * strjoin - Joins two strings with another string
 * @n: Address to store the size of the new string (optional)
 * @sep: Joining string
 * @pre: Prefix string
 * @suf: Suffix string
 * Return: Pointer to the new string
 */
char *strjoin(size_t *n, const char *sep, const char *pre, const char *suf)
{
    const char *strings[] = {pre ? pre : "", sep ? sep : "", suf ? suf : ""};
    size_t num_strings = sizeof(strings) / sizeof(strings[0]);
    size_t total_len = 0;

    for (size_t i = 0; i < num_strings; ++i)
        total_len += _strlen(strings[i]);

    char *dest = malloc(total_len + 1);
    if (dest)
    {
        char *pos = dest;
        for (size_t i = 0; i < num_strings; ++i)
        {
            pos = _strcpy(pos, strings[i]);
        }

        if (n)
            *n = total_len;
    }
    return dest;
}

/**
 * strjoina - Join strings from a NULL-terminated array
 * @n: Address to store the length of the new string (optional)
 * @sep: Joining string
 * @array: Array of strings
 * Return: Pointer to the new string
 */
char *strjoina(size_t *n, const char *sep, const char **array)
{
    size_t sep_len = _strlen(sep ? sep : "");
    size_t total_len = 0;

    for (size_t i = 0; array[i]; ++i)
        total_len += _strlen(array[i]);

    if (total_len > 0)
    {
        total_len += (sep_len * (i - 1));
        char *dest = malloc(total_len + 1);
        if (dest)
        {
            char *pos = dest;
            for (size_t i = 0; array[i]; ++i)
            {
                pos = _strcpy(pos, array[i]);
                if (i < (total_len / sep_len))
                    pos = _strcpy(pos, sep);
            }

            if (n)
                *n = total_len;
            return dest;
        }
    }

    return NULL;
}

/**
 * strjoinl - Joins a NULL-terminated list of strings with a character
 * @n: Address to store the length of the new string (optional)
 * @sep: Joining string
 * @...: Strings
 * Return: Pointer to the new string
 */
char *strjoinl(size_t *n, const char *sep, ...)
{
    va_list ap;
    size_t total_len = 0;
    size_t num_strings = 0;
    size_t sep_len = _strlen(sep ? sep : "");

    va_start(ap, sep);
    for (const char *temp = va_arg(ap, const char *); temp; temp = va_arg(ap, const char *))
    {
        total_len += _strlen(temp);
        num_strings++;
    }
    va_end(ap);

    if (total_len > 0)
    {
        total_len += (sep_len * (num_strings - 1));
        char *dest = malloc(total_len + 1);
        if (dest)
        {
            char *pos = dest;
            va_start(ap, sep);
            for (const char *temp = va_arg(ap, const char *); temp; temp = va_arg(ap, const char *))
            {
                pos = _strcpy(pos, temp);
                if (num_strings > 1)
                    pos = _strcpy(pos, sep);
                num_strings--;
            }
            va_end(ap);

            if (n)
                *n = total_len;
            return dest;
        }
    }

    return NULL;
}

