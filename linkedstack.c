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

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
