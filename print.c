#include "monty.h"

/**
 * print_all - prints all elements of a satck or queue
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) stack;
	(void) line_number;

	if (!exec_code.data_size)
		return;

	current = exec_code.data_t;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
