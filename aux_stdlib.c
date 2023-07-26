#include "main.h"

/**
 * get_len - Gets the length of a no.
 * @n: int var
 * Return: length of number.
 */
int get_len(int n)
{
	unsigned int y;
	int len = 1;

	if (n < 0)
	{
		len++;
		y = n * -1;
	}
	else
	{
		y = n;
	}
	while (y > 9)
	{
		len++;
		y = y / 10;
	}

	return (len);
}
/**
 * aux_itoa - function converts integer to string.
 * @n: int num
 * Return: String.
 */
char *aux_itoa(int n)
{
	unsigned int n1;
	int len = get_len(n);
	char *buf;

	buf = malloc(sizeof(char) * (len + 1));
	if (buf == 0)
		return (NULL);

	*(buf + len) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buf[0] = '-';
	}
	else
	{
		n1 = n;
	}

	len--;
	do {
		*(buf + len) = (n1 % 10) + '0';
		n1 = n1 / 10;
		len--;
	}
	while (n1 > 0)
		;
	return (buf);
}

/**
 * _atoi - Function that converts a string to an integer.
 * @s: input str.
 * Return: int.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;
	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)

				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
