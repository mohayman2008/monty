#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	(void) stack;

	if (exec_code.data_size < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = exec_code.data_t->prev->n;
	exec_code.data_t->prev->n = exec_code.data_t->n;
	exec_code.data_t->n = tmp;
}

/**
 * to_queue - change the data type to queue
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void to_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	exec_code.data_type = 1;
}

/**
 * to_stack - change the data type to stack
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void to_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	exec_code.data_type = 0;
}
