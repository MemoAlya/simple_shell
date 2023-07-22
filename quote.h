#ifndef _QUOTE_H_
#define _QUOTE_H_

#include <stdlib.h>

/**
 * enum quote_state - Enumeration of quote states.
 *
 * @QUOTE_NONE: In an unquoted sequence of blanks.
 * @QUOTE_WORD: In an unquoted sequence of non-blanks.
 * @QUOTE_DOUBLE: Inside double quotes.
 * @QUOTE_SINGLE: Inside single quotes.
 * @QUOTE_ESCAPE: Following a backslash.
 */
typedef enum quote_state
{
	QUOTE_NONE   = 0x0,
	QUOTE_WORD   = 0x1,
	QUOTE_DOUBLE = 0x2,
	QUOTE_SINGLE = 0x4,
	QUOTE_ESCAPE = 0x8
} quote_state_t;

typedef size_t (*quote_state_fp)(const char *, quote_state_t *);

/**
 * quote_state - Determine the quote state of a character.
 *
 * @c: The character to analyze.
 * Return: The corresponding quote_state_t value.
 */
quote_state_t quote_state(char c);

/**
 * quote_state_f - Get the quote state function pointer based on a given state.
 *
 * @s: The quote_state_t state.
 * Return: Function pointer corresponding to the given quote state.
 */
quote_state_fp quote_state_f(quote_state_t s);

/**
 * quote_state_len - Compute the length of the current quote state.
 *
 * @str: The input string to analyze.
 * @state: The current quote state.
 * Return: The length of the quote state.
 */
size_t quote_state_len(const char *str, quote_state_t state);

/**
 * _quote_state_none - Handler for the QUOTE_NONE state.
 * ...
 */

/**
 * _quote_state_word - Handler for the QUOTE_WORD state.
 * ...
 */

/**
 * _quote_state_double - Handler for the QUOTE_DOUBLE state.
 * ...
 */

/**
 * _quote_state_single - Handler for the QUOTE_SINGLE state.
 * ...
 */

/**
 * _quote_state_escape - Handler for the QUOTE_ESCAPE state.
 * ...
 */

/**
 * _isspecial_double - Check if a character is special inside double quotes.
 * ...
 */

/**
 * dequote - Remove quotes from a given string.
 *
 * @str: The input string with quotes.
 * Return: A dynamically allocated string with quotes removed.
 */
char *dequote(const char *str);

/**
 * dequote_len - Calculate the length of the dequoted string.
 *
 * @str: The input string with quotes.
 * Return: The length of the dequoted string.
 */
size_t dequote_len(const char *str);

#endif /* _QUOTE_H_ */

