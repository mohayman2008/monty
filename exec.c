#include "monty.h"

/**
 * exit_now - frees allocated memory and exits on error
 */
void exit_now(void)
{
	free_all(exec_code.to_free);
	exit(EXIT_FAILURE);
}

/**
 * nop - does nothing
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
