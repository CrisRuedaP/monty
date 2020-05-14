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
