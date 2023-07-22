#include "tokens.h"

/**
 * tokenize - Split a string into words (tokens) and dequote them.
 * @str: The string to tokenize.
 * 
 * Return: If memory allocation fails or if `str` is NULL or contains no tokens, return NULL.
 * Otherwise, return an array containing the tokens in `str`, terminated by a NULL pointer.
 */
char **tokenize(const char *str)
{
    char **tokens;
    const char *tok;
    size_t count;
    quote_state_t state;

    if (!str)
        return NULL;

    tokens = malloc(sizeof(char *) * (count_tokens(str) + 1));
    if (!tokens)
        return NULL;

    for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
    {
        tok = str;

        while (*str && (state = quote_state(*str)) != QUOTE_NONE)
        {
            if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
                str += quote_state_len(str + 1, state) + 1;
            else
                str += quote_state_len(str, state);

            if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
                ++str;
        }

        tokens[count] = _memdup(tok, str - tok + 1);
        if (!tokens[count])
        {
            free_tokens(&tokens);
            return NULL;
        }
        tokens[count][str - tok] = '\0';
    }
    tokens[count] = NULL;

    return tokens;
}


/**
 * count_tokens - Compute the number of tokens in a string after dequoting.
 * @str: The string to evaluate.
 * 
 * Return: Return the number of tokens in `str` after dequoting.
 */
size_t count_tokens(const char *str)
{
    size_t count;
    quote_state_t state;

    for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
    {
        while (*str && (state = quote_state(*str)) != QUOTE_NONE)
        {
            if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
                str += quote_state_len(str + 1, state) + 1;
            else
                str += quote_state_len(str, state);

            if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
                ++str;
        }
    }
    return count;
}


/**
 * tokenize_noquote - Split a string into words (tokens) without considering quotes.
 * @str: The string to tokenize.
 * 
 * Return: If memory allocation fails or if `str` is NULL or contains no tokens, return NULL.
 * Otherwise, return an array containing the tokens in `str`, terminated by a NULL pointer.
 */
char **tokenize_noquote(const char *str)
{
    char **tokens;
    const char *tok;
    size_t count;

    if (!str)
        return NULL;

    tokens = malloc(sizeof(char *) * (count_tokens_noquote(str) + 1));
    if (!tokens)
        return NULL;

    for (count = 0; *str; ++count)
    {
        while (_isspace(*str))
            ++str;
        if (!*str)
            break;

        tok = str;
        do {
            ++str;
        } while (*str && !_isspace(*str));

        tokens[count] = _memdup(tok, str - tok + 1);
        if (!tokens[count])
        {
            free_tokens(&tokens);
            return NULL;
        }
        tokens[count][str - tok] = '\0';
    }
    tokens[count] = NULL;

    return tokens;
}


/**
 * count_tokens_noquote - Count the number of words (tokens) in a string without considering quotes.
 * @str: The string to evaluate.
 * 
 * Return: If `str` is NULL, return -1. Otherwise, return the number of words in `str`.
 */
size_t count_tokens_noquote(const char *str)
{
    size_t tok_count;

    for (tok_count = 0; *str; ++tok_count)
    {
        while (_isspace(*str))
            ++str;
        if (!*str)
            break;
        do {
            ++str;
        } while (*str && !_isspace(*str));
    }
    return tok_count;
}


/**
 * free_tokens - Free and nullify an array of strings.
 * @tokens: Pointer to an array of tokens.
 */
void free_tokens(char ***tokens)
{
    char **tok;

    if (!tokens)
        return;

    tok = *tokens;
    if (!tok)
        return;

    while (*tok)
        free(*tok++);
    free(*tokens);

    *tokens = NULL;
}
 
