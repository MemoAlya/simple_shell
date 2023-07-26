#include "main.h"

/**
 * without_comment - function deletes comments from the input
 *
 * @in: input str
 * Return: input 
 */
char *without_comment(char *in)
{
	int i, up_t;

	up_t = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_t = i;
		}
	}

	if (up_t != 0)
	{
		in = _realloc(in, i, up_t + 1);
		in[up_t] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: data needed
 *
 * Return: nothing
 */
void shell_loop(data_shell *datash)
{
	int l, i_eof;
	char *input;

	l = 1;
	while (l == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			l = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			l = 0;
			free(input);
		}
	}
}
