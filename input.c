#include "hsh.h"
#include "getline.h"

/**
 * read_input - Read input from the user.
 * @info: Shell information
 *
 * Return: True if a complete command line is ready, False otherwise.
 */
bool read_input(info_t *info)
{
    char *line = NULL;
    char *temp = NULL;

    if (info->interactive)
        write(STDERR_FILENO, "$ ", 2);

    info->lineno += 1;

    while (read_multi_line_command(&line, info->fileno))
    {
        temp = line;
        line = strjoin(NULL, "", temp, info->line);
        free(temp);
        free(info->line);

        if (info->interactive)
            write(STDERR_FILENO, "> ", 2);

        info->lineno += 1;
    }

    if (line)
    {
        temp = info->line;
        info->line = strjoin(NULL, "", line, temp);
        free(temp);
        free(line);
    }

    return true;
}

/**
 * read_multi_line_command - Read a single line or a multi-line command.
 * @lineptr: Line buffer
 * @fd: File descriptor to read from
 *
 * Return: True if the command is complete, False if it's a multi-line command.
 */
bool read_multi_line_command(char **lineptr, int fd)
{
    char *line = *lineptr = _getline(fd);
    static quote_state_t state = QUOTE_NONE;
    size_t index = 0;

    if (line)
    {
        switch (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
        {
            case QUOTE_DOUBLE:
            case QUOTE_SINGLE:
                do {
                    index += quote_state_len(line + index, state);
                    if (line[index] == '\0')
                        continue;
                    if (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
                        index += 1;
                // fall through

            case 0:
                    state = quote_state(line[index]);
                    if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
                        index += 1;
                } while (line[index]);
        }
    }

    return !(state & (QUOTE_DOUBLE | QUOTE_SINGLE));
}

