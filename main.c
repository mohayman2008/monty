#include "monty.h"

monty exec_code = {NULL, 0, 0, NULL, NULL};

/**
 * iterate - iterate through, parse and execute lines
 *			in Monty 0.98 byte code file
 * @ifile: Monty 0.98 byte code file
 */
void iterate(FILE *ifile)
{
	char *line_buf = NULL;
	int line_num = 1;

	while (get_code_line(ifile, &line_buf))
	{
		exec_code.tokens = get_tokens(line_buf);
		parse(exec_code.tokens, line_num, &exec_code.data_h);

		if (exec_code.tokens)
			free_tokens(&exec_code.tokens);
		line_num++;
	}

	if (line_buf)
		free(line_buf);
}

/**
 * main - iterate through Monty 0.98 byte code file
 * @ac: num of arguments
 * @av: arguments vector
 *
 * Return: EXIT_SUCCESS on success
 */
int main(int ac, char **av)
{
	FILE *source;

	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	source = fopen(av[1], "r");
	if (!source)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]), exit(EXIT_FAILURE);

	iterate(source);

	fclose(source);
	return (EXIT_SUCCESS);
}