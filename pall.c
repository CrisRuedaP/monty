#include "monty.h"
/**
 * 
 * 
 * 
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	if (*stack == NULL)
		return;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	while (tmp->prev != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
	printf("%d\n", tmp->n);
	(void)line_number;
}