#include "monty.h"
/**
 * mul_op - Multiplies the top 2 element of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i = 0;

	if (*stack == NULL)
	{
		err_status = 6;
		return;
	}
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		err_status = 7;
		return;
	}
	tmp = tmp->prev;
	tmp->n = tmp->n * tmp->next->n;
	pop_op(stack, line_number);
}

