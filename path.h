#ifndef PATH_H
#define PATH_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "info.h"
#include "list.h"
#include "string.h"
#include "types.h"

/**
 * Searches for a file in the specified paths.
 * 
 * @param info The info_t structure.
 * @param path The linked list of paths to search in.
 * @return A pointer to a string containing the path of the found file,
 *         or NULL if the file is not found.
 */
char *search_path(info_t *info, list_t *path);

#endif /* PATH_H */

