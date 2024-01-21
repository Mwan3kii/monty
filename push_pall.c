#include "monty.h"
/**
 * push_node - pushes node to stack
 * @stack: the stacked
 * @line_number: the line number
 * @value: the value
 */
void push_node(stack_t **stack, __attribute__((unused))unsigned int line_number, int value)
{
	stack_t *new_node;
	
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for new node\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * push - pushes the elements to stack
 * @line_number: line number
 * @stack: the stack
 * @value: the element
 */
void push(stack_t **stack, unsigned int line_number, char *value)
{
	int num;
	
	if (value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(value);
	if (num == 0 && value[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push_node(stack, line_number, num);
}
/**
 * pall - prints the top of stack
 * @stack: the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	(void)line_number;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
