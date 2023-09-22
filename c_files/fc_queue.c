#include "monty.h"

/**
 * fc_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void fc_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * fc_addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: void
*/
void fc_addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error!!!\n");
	}

	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
