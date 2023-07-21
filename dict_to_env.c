#include "env.h"

/**
 * dict_to_env - function creates linked list from environment
 * @head: args passed
 * Return: ptr to list
 */
char **dict_to_env(env_t *head)
{
	env_t *tmp = head;
	char **env;
	size_t len = 0;

	while (tmp)
		++len, tmp = tmp->next;

	env = malloc(sizeof(char *) * (len + 1));
	if (!env)
		return (NULL);

	for (len = 0; head; head = head->next)
		env[len++] = strjoin(NULL, "=", head->key, head->val);
	env[len] = NULL;

	return (env);
}
