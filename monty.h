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
 * struct monty_s - reference of stack or queue
 * @tokens: the tokens of the next instruction line
 * @data_type: type of data set (0: stack, 1: queue)
 * @data_size: number of elements
 * @data_h: head of the data set
 * @data_t: head of the data set
 */
typedef struct monty_s
{
	char **tokens;
	int data_type;
	int data_size;
	stack_t *data_h;
	stack_t *data_t;
} monty;

extern monty exec_code;

/*--------------------------parser.c--------------------------*/
char *get_code_line(FILE *ifile, char **buf, size_t *buf_size);
char **get_tokens(char *line);
void parse(char **tokens, int line_num, stack_t **stack);

/*--------------------------errors.c--------------------------*/
void malloc_error(void);

/*--------------------------memory.c--------------------------*/
void *_realloc(void *ptr, size_t new_size);

/*---------------------------free.c---------------------------*/
void free_tokens(char ***tokens);
void free_data(void);

/*--------------------------data_io.c-------------------------*/
void push(stack_t **stack, unsigned int line_number);
int pop_item(void);
void pop(stack_t **stack, unsigned int line_number);

/*-------------------------data_mgmt.c------------------------*/
void swap(stack_t **stack, unsigned int line_number);

/*------------------------arithmetic.c------------------------*/
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

/*--------------------------print.c---------------------------*/
void print_all(stack_t **stack, unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);

/*---------------------------main.c---------------------------*/
void iterate(FILE *ifile);

#endif /* __MONTY_H__ */
