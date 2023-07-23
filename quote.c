#include "quote.h"

/**
 * quote_state - get the state associated with a given character
 * @c: character
 *
 * Return: the state associated with c
 */
quote_state_t quote_state(char c)
{
    if (_isspace(c))
        return QUOTE_NONE;
    if (c == '"')
        return QUOTE_DOUBLE;
    if (c == '\'')
        return QUOTE_SINGLE;
    if (c == '\\')
        return QUOTE_ESCAPE;
    return QUOTE_WORD;
}

/**
 * quote_state_f - get the function associated with a given state
 * @s: state
 *
 * Return: the state function pointer
 */
quote_state_fp quote_state_f(quote_state_t s)
{
    switch (s)
    {
        case QUOTE_NONE:
            return _quote_state_none;
        case QUOTE_WORD:
            return _quote_state_word;
        case QUOTE_DOUBLE:
            return _quote_state_double;
        case QUOTE_SINGLE:
            return _quote_state_single;
        case QUOTE_ESCAPE:
            return _quote_state_escape;
    }
    return NULL;
}

/**
 * quote_state_len - get the length of a given state
 * @str: string
 * @state: state
 *
 * Return: the length of the state
 */
size_t quote_state_len(const char *str, quote_state_t state)
{
    quote_state_fp state_handler = quote_state_f(state);
    if (state_handler)
        return state_handler(str, NULL);
    return 0; // Or any other appropriate value to indicate an error.
}

