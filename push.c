#include "monty.h"

/**
 * perr - func to print in stderr
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void perr(stack_t **head, int counter)
{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
	fclose(drivers.file);
	free(drivers.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
/**
 * f_push - func to print in stderr
 * @head: stack head
 * @counter: no used
 * Return: no return
*/

void f_push(stack_t **head, unsigned int counter)
{
	int j = 0, n;
	int flag;


	if (!drivers.arg)
	{
		perr(head, counter);
	}
	if (drivers.arg[0] == '-')
		j++;
	while (drivers.arg[j] != '\0')
	{
		if (drivers.arg[j + 1] == '\0' & drivers.arg[j] == '$')
			drivers.arg[j] == '\0';
		if (drivers.arg[j] > 57 || drivers.arg[j] < 48)
			perr(head, counter);
		j++;
	}
	n = atoi(drivers.arg);
	add_dnodeint(head, n);
}
