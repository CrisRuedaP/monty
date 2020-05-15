#include "monty.h"
/**
 * pop_op - Remove the top element of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		err_status = 3;
		return;
	}
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	if (tmp->prev != NULL)
	{
		tmp->prev->next = NULL;
		free(tmp);
	}
	(void)line_number;
}
