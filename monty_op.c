#include "monty.h"
#include <string.h>
/**
 * select_op - 
 * 
 * 
 */
int select_op(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t funct_op[] = {
	    {"pall", pall_op},
	    {NULL, NULL}};
	/*{"pint", pint_op},*/
	/*{"pop", pop_op},*/
	int i = 0;
	while (funct_op[i].opcode != NULL)
	{
		if (strcmp(opcode, funct_op[i].opcode) == 0)
			(funct_op[i].f)(stack, line_number);
		i++;
		return (0);
	}
	return (-1);
}
int main(int argc, char *argv[])
{
	FILE *fd;
	stack_t *stack = NULL;
	char *buffer = NULL;
	size_t len_buff = 0;
	ssize_t bytes_read = 0;
	unsigned int line_number = 0;
	char *opcode = NULL;
	char *tokens = NULL;
	int select = 0;
	if (argc != 2) /*Verifica cantidad de argumentos*/
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (bytes_read != -1)
	{
		bytes_read = getline(&buffer, &len_buff, fd);
		if (bytes_read == -1)
			break;
		line_number++;
		opcode = strtok(buffer, DELIM);
		if (strcmp(opcode, "push") == 0)
		{
			tokens = strtok(NULL, DELIM);
			if (tokens == NULL)
			{
				printf("L%u: unknown instruction %s", line_number, opcode);
				exit(EXIT_FAILURE);
			}
			else
			{
				push_op(&stack, line_number, tokens);
			}
		}
		else
		{
			select = select_op(opcode, &stack, line_number);
			if (select == -1)
			{
				printf("L%u: unknown instruction %s", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
