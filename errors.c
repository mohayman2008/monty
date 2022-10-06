#include "monty.h"

/**
 * malloc_error - print error message and exit
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit_now();
}

/**
 * print_error_exit - print error message and exit
 * @error_msg: error message
 */
void print_error_exit(char *error_msg)
{
	fprintf(stderr, "%s\n", error_msg);
	exit_now();
}
