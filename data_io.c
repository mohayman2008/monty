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
	int num;
	char *errmsg = "usage: push integer";

	(void) stack;

	if (!exec_code.tokens[1])
/*		|| !(isdigit(exec_code.tokens[1][0]) || exec_code.tokens[1][0] == '-' ||*/
/*			exec_code.tokens[1][0] == '+'))*/
		/* print_error(line_number, errmsg) */
		fprintf(stderr, "L%u: %s\n", line_number, errmsg),
		exit(EXIT_FAILURE);
	num = strtol(exec_code.tokens[1], NULL, 10);
	if (errno == ERANGE)
		fprintf(stderr, "L%u: %s\n", line_number, errmsg),
		exit(EXIT_FAILURE);

	new = malloc(sizeof(*new));
	if (!new)
		malloc_error();
	new->n = num;

	if (!exec_code.data_type) /* stack */
	{
		new->prev = exec_code.data_t;
		new->next = NULL;
		if (exec_code.data_t)
			exec_code.data_t->next = new;
		exec_code.data_t = new;
		if (!exec_code.data_size)
			exec_code.data_h = new;

	}
	else
		enqueue(new);

	exec_code.data_size++;
}

/**
 * pop_item - pops an element of the top of the satck and returns its value
 *		(doesn't check for errors and shouldn't be called directly)
 *
 * Return: the value of the popped element
 */
int pop_item(void)
{
	stack_t *tail;
	int n;

	tail = exec_code.data_t;
	n = tail->n;
	if (tail->prev)
		tail->prev->next = NULL;
	exec_code.data_t = tail->prev;

	exec_code.data_size--;
	if (!exec_code.data_size)
		exec_code.data_h = NULL;

	free(tail);
	return (n);
}

/**
 * pop - pops an element of the top of the satck
 * @stack: stack or queue head
 * @line_number: number of the line starting from 1
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (!exec_code.data_size)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	pop_item();
}

/**
 * enqueue - enqueue a stack_t new node to the queue
 *	(doesn't perform any errorchecks and shouldn't be called directly)
 * @node: newly created stack_t node
 */
void enqueue(stack_t *node)
{
	node->prev = NULL;
	node->next = exec_code.data_h;
	if (exec_code.data_h)
		exec_code.data_h->prev = node;
	exec_code.data_h = node;
	if (!exec_code.data_size)
		exec_code.data_t = node;
}
