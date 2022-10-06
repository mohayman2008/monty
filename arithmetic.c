#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	(void) stack;

	if (exec_code.data_size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tail = exec_code.data_t->prev;
	tail->n += pop_item();
}

/**
 * sub - subtracts the top element of the stack from the second top element
 *	of the stack
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	(void) stack;

	if (exec_code.data_size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tail = exec_code.data_t->prev;
	tail->n -= pop_item();
}
