#include "monty.h"

/**
* assign - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* Return: state integer
*/
int assign(stack_t **stack, unsigned int counter)
{	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;
	char *arg;

	op = strtok(drivers.content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	drivers.arg = strtok(NULL, " \n\t");
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
		fclose(drivers.file);
		free(drivers.content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
