#ifndef __MONTY_H__
#define __MONTY_H__

#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define DELIM " \t\v\3\4\n\r\f\0"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct dataset_s - reference of stack or queue
 * @type: type of data set (0: stack, 1: queue)
 * @size: number of elements
 * @head: head of the data set
 * @tail: head of the data set
 */
typedef struct dataset_s
{
	int type;
	int size;
	stack_t *head;
	stack_t *tail;
} dataset;

extern dataset data;

/*--------------------------parser.c--------------------------*/
char *get_code_line(FILE *ifile, char **buf);
char **get_tokens(char *line);
void parse(char **tokens, int line_num, stack_t **stack);

/*--------------------------errors.c--------------------------*/
void malloc_error(void);

/*--------------------------memory.c--------------------------*/
void *_realloc(void *ptr, size_t new_size);

/*---------------------------free.c---------------------------*/
void free_tokens(char **tokens);

/*---------------------------main.c---------------------------*/
void iterate(FILE *ifile, stack_t **stack);

#endif /* __MONTY_H__ */
