#include "monty.h"
/**
 * prints_stack - prints the stack
 * @stack: stacked to be printed
 * @line_number: line number
 */
void prints_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
	{
		fprintf(stderr, "Error: Failed to print stack\n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pops_top - removes top node from stack
 * @stack: the stack to remove from
 * @line_number: the line number
 */
void pops_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		stack_errors(7, line_number);
		return;
	}
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;
	
	if (new_node == NULL || *new_node == NULL)
	{
		fprintf(stderr, "Error: Failed to add node to stack\n");
		exit(EXIT_FAILURE);
	}
	if (h == NULL)
	{
		h = *new_node;
		return;
	}
	temp = h;
	h = *new_node;
	h->next = temp;
	temp->prev = h;
}
/**
 * prints_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void prints_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		stack_errors(6, line_number);
		return;
	}
	printf("%d\n", (*stack)->n);
}
