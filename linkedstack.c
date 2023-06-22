#include "monty.h"
/**
 * add_dnodeint - add node to stack
 * @head: stack head
 * @n: num to insert
 * Return: the added node
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{

	stack_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;
	new->prev = NULL;


	if (!(*head))
	{
		*head = new;
		return (*head);
	}
	else
	{
		new->next = (*head);
		(*head)->prev = new;
		*head = new;
	}
	return (new);
}
