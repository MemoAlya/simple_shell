#include "hsh.h"

/**
 * remove_comments - remove comments (#) from a command
 * @cmd: pointer to the cmd to process
 */
void remove_comments(cmdlist_t *cmd)
{
    char **tokens = cmd->tokens;
    char **new_tokens = NULL;

    // Find the index of the first comment (if any)
    int comment_index = 0;
    while (tokens[comment_index] && tokens[comment_index][0] != '#')
        comment_index++;

    if (tokens[comment_index])
    {
        // Allocate memory for the new array with non-comment tokens
        new_tokens = (char **)malloc((comment_index + 1) * sizeof(char *));
        if (!new_tokens)
        {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        // Copy non-comment tokens to the new array
        for (int i = 0; i < comment_index; ++i)
            new_tokens[i] = strdup(tokens[i]);

        new_tokens[comment_index] = NULL;

        // Free old tokens array and update with the new one
        free_tokens(&(cmd->tokens));
        cmd->tokens = new_tokens;

        // Free the rest of the command after the comment
        free_cmdlist(&(cmd->next));
    }
}

