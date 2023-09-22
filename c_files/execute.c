#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: 0 on success, 1 on error
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", fc_push}, {"pall", fc_pall}, {"pint", fc_pint},
				{"pop", fc_pop},
				{"swap", fc_swap},
				{"add", fc_add},
				{"nop", fc_nop},
				{"sub", fc_sub},
				{"div", fc_div},
				{"mul", fc_mul},
				{"mod", fc_mod},
				{"pchar", fc_pchar},
				{"pstr", fc_pstr},
				{"rotl", fc_rotl},
				{"rotr", fc_rotr},
				{"queue", fc_queue},
				{"stack", fc_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
