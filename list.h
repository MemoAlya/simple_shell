#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/**
 * struct list - singly linked list
 * @str: dynamically-allocated string
 * @next: pointer to the next node
 */
typedef struct list {
    char *str;
    struct list *next;
} list_t;

list_t *str_to_list(const char *str, char delim);
void free_list(list_t *head);

#endif /* LIST_H */

