#include "monty.h"

/**
 * free_tokens - frees a malloc-ed array of malloc-ed strings
 * @tokens: array of strings
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (!tokens)
		return;

	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}
