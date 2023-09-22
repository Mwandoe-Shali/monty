#include "monty.h"

/**
 * fc_pall - prints the stack
 * @head: stack head
 * @counter: not used in function
 * Return: void
*/
void fc_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
