#include "monty.h"
/**
 * error_pint - Error for empty stack
 * @line_number: Line number of the current opcode
 */
void error_pint(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
}
/**
 * error_pop - Error for empty stack
 * @line_number: Line number of the current opcode
 */
void error_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
}
/**
 * error_swap - Error for too short stack
 * @line_number: Line number of the current opcode
 */
void error_swap(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
}
/**
 * error_add - Error for too short stack
 * @line_number: Line number of the current opcode
 */
void error_add(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
}
