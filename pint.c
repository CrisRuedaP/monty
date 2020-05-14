#include "monty.h"
/**
 * pint_op - Print the value at the top of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{

		err_status = 2;
		return;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;

	}
	printf("%d\n", tmp->n);
	(void)line_number;

}
