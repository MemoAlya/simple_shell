#include "path.h"

/**
 * search_path - searches for the directory with the executable program
 * @info: Argument passed.
 * @path: Argument passed.
 * Return: Pointer to directory string containing the executable program.
 *         Returns NULL if the executable is not found in any directory.
 */
char *search_path(info_t *info, list_t *path)
{
    char *pathname = NULL;
    struct stat sb;

    while (path)
    {
        if (*path->str == '\0')
        {
            pathname = strjoin(NULL, "/", info->cwd, *info->tokens);
        }
        else
        {
            pathname = strjoin(NULL, "/", path->str, *info->tokens);
        }

        if (stat(pathname, &sb) == 0 && S_ISREG(sb.st_mode))
        {
            return pathname;
        }

        free(pathname);
        path = path->next;
    }

    return NULL;
}

