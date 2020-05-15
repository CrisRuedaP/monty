#include "monty.h"
/**
 * error_usage - Error when user doesn't give any file
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * error_open - Its not possible to open the file
 * @file_name: Files name
 */
void error_open(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}
/**
 * error_unknown - Error for invalid instruction
 * @opcode:String with the operation code
 * @line_number: Line number of the current opcode
 */
void error_unknown(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
}

/**
 * id_status - Check's for type of error
 * @stack: Double linked used to stack the integers
 * @l_number: Line number of the current opcode
 * @fd: File descriptor of the Monty's file
 * @buffer: Buffer that stores the line for getline
 */
void id_status(stack_t *stack, char *buffer, FILE *fd, unsigned int l_number)
{
	if (err_status == 2)
	{
		error_pint(l_number);
		free_errors(stack, buffer, fd);
	}
	if (err_status == 3)
	{
		error_pop(l_number);
		free_errors(stack, buffer, fd);
	}
	if (err_status == 4)
	{
		error_swap(l_number);
		free_errors(stack, buffer, fd);
	}
	if (err_status == 5)
	{
		error_add(l_number);
		free_errors(stack, buffer, fd);
	}
}
