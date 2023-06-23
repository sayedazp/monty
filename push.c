#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (drivers.arg)
	{
		if (drivers.arg[0] == '-')
			j++;
		for (; drivers.arg[j] != '\0'; j++)
		{
			if (drivers.arg[j] > 57 || drivers.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(drivers.file);
			free(drivers.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(drivers.file);
		free(drivers.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(drivers.arg);
	if (drivers.lifi == 0)
		addnode(head, n);
}
