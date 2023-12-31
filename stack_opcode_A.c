#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack. (func push)
 * @new_node: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 *
 * Return: Void
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;
	stack_t *head = NULL;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Prints nodes of the stack. (func pall)
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: line number of  the opcode.
 *
 * Return: void
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack. (func pop)
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: Void
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_errs(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack. (func pint)
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: Void
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_errs(6, line_number);
	printf("%d\n", (*stack)->n);
}

