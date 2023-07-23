#include "hsh.h"

/**
 * parse - parse input
 * @info: shell information
 *
 * Description: This function expands aliases, variables, and word splitting
 *
 * Return: the final number of tokens
 */
int parse(info_t *info)
{
    size_t n = 0;
    cmdlist_t *cmd = info->commands = cmd_to_list(info->line);

    while (cmd)
    {
        // Remove comments from the command
        remove_comments(cmd);

        // Check if the command has tokens
        if (!cmd->tokens)
        {
            cmd = cmd->next;
            del_cmd(&(info->commands), n);
            continue;
        }

        // Expand aliases, variables, and dequote tokens
        if (expand_command(info, cmd))
        {
            // Move to the next command and increment the command count
            cmd = cmd->next;
            ++n;
        }
        else
        {
            // If the command has no tokens after processing, skip it
            cmd = cmd->next;
            del_cmd(&(info->commands), n);
        }
    }

    // Return the final number of tokens
    return n;
}

/**
 * expand_command - expand aliases, variables, and dequote tokens
 * @info: shell information
 * @cmd: command to expand
 *
 * Return: 1 on success, 0 if no tokens left after processing
 */
int expand_command(info_t *info, cmdlist_t *cmd)
{
    char **tokens, *tok;

    // Expand aliases in the command tokens
    expand_aliases(info->aliases, &(cmd->tokens));

    // Check if the command has tokens after alias expansion
    if (!cmd->tokens)
        return 0;

    // Expand variables in the command tokens
    expand_vars(info, &(cmd->tokens));

    // Check if the command has tokens after variable expansion
    if (!cmd->tokens)
        return 0;

    // Dequote the tokens (remove quotes) in the command tokens
    tokens = cmd->tokens;
    for (tok = *tokens; tok; tok = *(++tokens))
    {
        *tokens = dequote(tok);
        free(tok);
    }

    return 1;
}

