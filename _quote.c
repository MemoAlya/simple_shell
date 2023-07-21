#include "quote.h"

/**
 * _quote_state_none - function to get state length and next state
 * @str: string parameter
 * @state: state
 *
 * Return: len of state
 */
size_t _quote_state_none(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (_isspace(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * _quote_state_word - get state length and next state
 * @str: string
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_word(const char *str, quote_state_t *state)
{
	size_t length = 0;

	while (*str && !_isspace(*str) && !_isquote(*str))
		++str, ++length;
	if (state && *str)
		*state = quote_state(*str);
	return (length);

/**
 * _quote_state_double - function to get state length and next state
 * @str: string parmeter
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_double(const char *str, quote_state_t *state)
{
	size_t lenght = 0;

	while (*str && *str != '"')
		++str, ++length;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (length);


/**
 * _quote_state_single - function gets the state length and next state
 * @str: string parameter
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_single(const char *str, quote_state_t *state)
{
	size_t length = 0;

	while (*str && *str != '\'')
		++str, ++length;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (length);


/**
 * _quote_state_escape - function gets the state's length and next state's
 * @str: string
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_escape(const char *str, quote_state_t *state)
{
	if (*str)
	{
		if (state && *(++str))
			*state = quote_state(*str);
		return (1);
	}
	return (0);
}

