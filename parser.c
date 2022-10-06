#include "monty.h"

/**
 * get_code_line - gets a line from an arbitary file
 * @ifile: input file
 * @buf: pointer to a buffer to store the line
 * @buf_size: size of the buffer
 *
 * Return: the new line or NULL if EOF has been reached
 */
char *get_code_line(FILE *ifile, char **buf, size_t *buf_size)
{
	if (getline(buf, buf_size, ifile) < 0)
	{
		if (!errno)
			return (NULL);
		malloc_error();
	}
	return (*buf);
}

/**
 * get_tokens - get tokens from a string and store them in a string array
 * @line: input string
 *
 * Return: the dynamically allocated strings array
 */
char **get_tokens(char *line)
{
	char **tokens = NULL, **new = NULL, *current = NULL;
	int size = 0, i = 0, size_inc = 4;

	if (!line)
		return (NULL);

	current = strtok(line, DELIM);
	while (current)
	{
		if (i >= size)
		{
			new = _realloc(tokens, sizeof(*tokens) * (size + size_inc + 1));
			if (!new)
				free(line), free_tokens(&tokens), malloc_error();
			tokens = new;
			size += size_inc;
		}
		tokens[i++] = strdup(current);
		current = strtok(NULL, DELIM);
	}
	if (size)
		tokens[i] = NULL;

	return (tokens);
}

/**
 * parse - parse and execute a line of monty code
 * @tokens: array of strings containg the tokens in a line of code
 * @line_num: number of the line in the file starting with 1
 * @stack: data stack (or queue)
 */
void parse(char **tokens, int line_num, stack_t **stack)
{
	instruction_t list[] = {{"push", push}, {"pall", print_all},
				{"pint", print_int}, {NULL, 0}};
	int i = 0;

	if (!tokens || !*tokens)
		return;

	for (; list[i].opcode ; i++)
	{
		if (!strcmp(tokens[0], list[i].opcode))
			list[i].f(stack, line_num);
	}
}
