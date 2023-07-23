#include <stdlib.h>
#include <stdio.h>

/**
 * num_to_str - converts number to string
 * @n: number passed
 * Return: pointer to dynamically allocated string
 */
char *num_to_str(size_t n)
{
    // Calculate the number of digits in the number n
    size_t tmp = n;
    size_t len = 1;
    while (tmp /= 10)
        len++;

    // Allocate memory for the string representation of the number
    char *buf = (char *)malloc(len + 1); // Add one for null-terminator
    if (!buf)
        return NULL;

    // Convert the number to a string and store it in the buffer
    char *ptr = buf + len;
    *ptr = '\0'; // Null-terminate the string
    do {
        *--ptr = '0' + n % 10; // Convert digit to character
        n /= 10;
    } while (n != 0);

    return buf;
}

int main()
{
    size_t number = 12345;
    char *str = num_to_str(number);

    if (str)
    {
        printf("Number as string: %s\n", str);
        free(str);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

