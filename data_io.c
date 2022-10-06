#include "monty.h"
#include <ctype.h>

/**
 * push - add an element to a satck or queue
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *errmsg = "usage: push integer";

	(void) stack;

	if (!exec_code.tokens[1] ||
		!(isdigit(exec_code.tokens[1][0]) || exec_code.tokens[1][0] == '-' ||
			exec_code.tokens[1][0] == '+'))
		/* print_error(line_number, errmsg) */
		fprintf(stderr, "L%u: %s\n", line_number, errmsg),
		exit(EXIT_FAILURE);

	if (!exec_code.data_type) /* stack */
	{
		new = malloc(sizeof(*new));
		if (!new)
			malloc_error();
		new->n = atoi(exec_code.tokens[1]);
		new->prev = exec_code.data_t;
		new->next = NULL;
		if (exec_code.data_t)
			exec_code.data_t->next = new;
		exec_code.data_t = new;
		if (!exec_code.data_size)
			exec_code.data_h = new;

		exec_code.data_size++;
	}
}
