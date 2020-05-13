#include "monty.h"
#include <string.h>
/*declarar MACRO DELIM*/

/**
 * 
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

int fill_args(char *buffer, char **arr_args)
{
	int token_count = 0;
	char *tokens, *aux = buffer, *opcode;

	opcode = strtok(buffer, DELIM);	       /**Extrae el comando 0 */
	arr_args[token_count] = opcode;	       /**Almacena command 1 en args*/
	while (aux != NULL && token_count < 3) /**Mientras que hayan tokens*/
	{
		++token_count;
		tokens = strtok(NULL, DELIM); /**Almacena el n argumento en parameter*/
		aux = tokens;
		arr_args[token_count] = tokens; /**almacena parameter i en args[i]*/
	}
	arr_args[token_count] = NULL; /**Marca el fin array*/
	free(arr_args);
	return (token_count); /**Retorna el length de args[]*/


}

int main(int argc, char *argv[])
{
	FILE *fd;
	stack_t **stack = NULL;
	char *buffer = NULL;
	size_t len_buff = 0;
	ssize_t bytes_read = 0;
	unsigned int line_number = 0;
	char *opcode = NULL;
	char *arr_args[20];
	int select = 0;

	if (argc != 2) /*Verifica cantidad de argumentos*/
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], O_RDONLY);
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (bytes_read != -1)
	{
		bytes_read = getline(&buffer, &len_buff, fd);
		line_number++;
		opcode = strtok(buffer, DELIM);
		fill_args(buffer, arr_args);
		if (arr_args[0] == NULL)
			continue;
		if (strcmp(arr_args[0], "push") == 0)
		{
			if (arr_args[2] != NULL)
			{
				printf("L%u: unknown instruction %s", line_number, opcode);
				exit(EXIT_FAILURE);
			}
			else
			{
				push_op(stack, line_number, arr_args[1]);
			}
		}
		else
		{
			select = select_op(arr_args[0], stack, line_number);
			if (select == -1)
			{
				printf("L%u: unknown instruction %s", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		free(buffer);
		free(opcode);
	}

	return (0);
}


