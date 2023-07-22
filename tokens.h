#ifndef TOKENS_H
#define TOKENS_H

#include <stddef.h>

// Tokenize the input string with quoted substrings
char **tokenize(const char *str);

// Tokenize the input string without considering quoted substrings
char **tokenize_noquote(const char *str);

// Count the number of tokens in the input string with quoted substrings
size_t count_tokens(const char *str);

// Count the number of tokens in the input string without considering quoted substrings
size_t count_tokens_noquote(const char *str);

// Free the memory allocated for the array of tokens
void free_tokens(char **tokens);

// Duplicate an array of strings and return a new array containing the same elements
char **arrdup(char **arr);

// Concatenate two arrays of strings and return a new array with the combined elements
char **arrjoin(char **arr1, char **arr2);

#endif /* TOKENS_H */

