#include "main.h"

/**
 * swap_char - function swaps | and & for non-printed chars
 *
 * @input: input str
 * @bool: type of swap
 * Return: swapped string
 */
char *swap_char(char *input, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * add_nodes - function adds separators and command lines in the lists   *
 * @head_s: head of sep list
 * @head_l: head of cmd lines list
 * @input: input string
 * Return: nothing
 */
void add_nodes(sep_list **head_s, line_list **head_l, char *input)
{
	int j;
	char *lin;

	input = swap_char(input, 0);

	for (j = 0; input[j]; j++)
	{
		if (input[j] == ';')
			add_sep_node_end(head_s, input[j]);

		if (input[j] == '|' || input[j] == '&')
		{
			add_sep_node_end(head_s, input[j]);
			j++;
		}
	}

	lin = _strtok(input, ";|&");
	do {
		lin = swap_char(lin, 1);
		add_line_node_end(head_l, lin);
		lin = _strtok(NULL, ";|&");
	} while (lin != NULL);

}

/**
 * go_next - Fucntion goes to the next command line stored
 *
 * @list_s: sep list
 * @list_l: command line list
 * @datash: data structure
 * Return: nothing
 */
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_sep;
	sep_list *ls_s;
	line_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - function splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @datash: data struc
 * @input: input str
 * Return: 0 to exit, 1 to continue
 */
int split_commands(data_shell *datash, char *input)
{
	sep_list *head_x, *list_x;
	line_list *head_l, *list_l;
	int loop;

	head_x = NULL;
	head_l = NULL;

	add_nodes(&head_x, &head_l, input);

	list_x = head_x;
	list_l = head_l;

	while (list_l != NULL)

	{
		datash->input = list_l->line;
		datash->args = split_line(datash->input);
		loop = exec_line(datash);
		free(datash->args);

		if (loop == 0)
			break;

		go_next(&list_x, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}
	free_sep_list(&head_x);
	free_line_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - function tokenizes the input string
 *
 * @input: input str
 * Return: str splitted.
 */
char **split_line(char *input)
{
	size_t b_size;
	size_t j;
	char **tokens;
	char *token;

	b_size = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (b_size));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (j = 1; token != NULL; j++)
	{
		if (j == b_size)
		{
			b_size += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, j, sizeof(char *) * b_size);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[j] = token;
	}

	return (tokens);
}
