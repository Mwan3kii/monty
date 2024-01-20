#include "monty.h"
/**
 * add_to_stack - add to tops pf stack
 * @new_node: node to add
 * @lnum: line_number
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int lnum)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
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
 * prints_stack - prints the stack
 * @stack: stacked to be printed
 * @line_number: line number
 */
void prints_stack(stack_t **stack, unsigned int line_number)
{
	const char *argument = " \n";
	stack_t *new_node;

	if (!stack || !line_number)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(argument);
	new_node->prev = NULL;
	new_node->prev = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
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
		stack_errors(7, line_number);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * prints_top - prints top of stack
 * @stack: the stack
 * @line_number: the line_number
 */
void prints_top(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *curr = *stack;

	if (!stack || !*stack)
		return;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
