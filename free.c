#include "monty.h"

/**
 * free_tokens - frees a malloc-ed array of malloc-ed strings
 * @tokens: array of strings
 */
void free_tokens(char ***tokens)
{
	int i = 0;

	if (!tokens || !*tokens)
		return;

	while ((*tokens)[i])
		free((*tokens)[i++]);
	free(*tokens);
	*tokens = NULL;
}

/**
 * free_data - frees malloc-ed data (stack_t)s
 */
void free_data(void)
{
	stack_t *current, *next;

	current = exec_code.data_h;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	exec_code.data_h = NULL;
	exec_code.data_t = NULL;
}
