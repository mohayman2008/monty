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

/**
 * rot_left - rotates the stack to the top.
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void rot_left(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	(void) stack;
	(void) line_number;

	if (exec_code.data_t)
	{
		tail = exec_code.data_t;

		if (tail->prev)
			tail->prev->next = NULL;
		exec_code.data_t = tail->prev;
		tail->prev = NULL;

		tail->next = exec_code.data_h;
		if (tail->next)
			tail->next->prev = tail;
		exec_code.data_h = tail;
	}
}

/**
 * rot_right - rotates the stack to the top.
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void rot_right(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void) stack;
	(void) line_number;

	if (exec_code.data_h)
	{
		head = exec_code.data_h;

		if (head->next)
			head->next->prev = NULL;
		exec_code.data_h = head->next;
		head->next = NULL;

		head->prev = exec_code.data_t;
		if (head->prev)
			head->prev->next = head;
		exec_code.data_t = head;
	}
}
