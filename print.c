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

/**
 * print_int - prints the value on the top of the satck
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void print_int(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (!exec_code.data_size)
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);

	printf("%d\n", exec_code.data_t->n);
}
