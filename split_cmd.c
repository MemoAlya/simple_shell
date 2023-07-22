#include "command.h"

/**
 * split_cmd - split a command with NULL-bytes on unquoted semicolons
 * @cmd: the command to split
 *
 * This function splits the input command using NULL-bytes on unquoted semicolons.
 * It also handles quote states and escape characters within the command.
 *
 * Return: The total number of commands resulting from the split.
 */
size_t split_cmd(char *cmd)
{
    size_t count = 1;
    quote_state_t state;

    do {
        while (*cmd && (state = quote_state(*cmd)) != QUOTE_NONE)
        {
            if (state & QUOTE_WORD)
            {
                ssize_t sep_index = _strnchr(cmd, ';', _quote_state_word(cmd, NULL));
                if (sep_index != -1)
                {
                    cmd[sep_index] = '\0';
                    ++count;
                }
                cmd += sep_index + 1;
            }
            else if (state & QUOTE_ESCAPE)
            {
                if (*(cmd + 1) == '\n')
                    _strcpy(cmd, cmd + 2);
                else
                    cmd += 2;
            }
            else
            {
                cmd += quote_state_len(cmd + 1, state) + 1;
                if (*cmd && (state & (QUOTE_SINGLE | QUOTE_DOUBLE)))
                    ++cmd;
            }
        }
    } while (*cmd += quote_state_len(cmd, QUOTE_NONE));

    return count;
}

