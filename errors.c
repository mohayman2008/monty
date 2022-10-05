#include "monty.h"

/**
 * malloc_error - print error message and exit
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
