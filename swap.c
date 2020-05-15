#include "monty.h"
/**
 * swap_op - Swaps the top 2 elements of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *aux;
	int i = 0;

	if (*stack == NULL)
	{
		err_status = 4;
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
		err_status = 4;
		return;
	}
	aux = tmp->prev;
	aux->prev->next = tmp;
	tmp->prev = aux->prev;
	aux->prev = tmp;
	tmp->next = aux;
	aux->next = NULL;
	(void)line_number;
}
