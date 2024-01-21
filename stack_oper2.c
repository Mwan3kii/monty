#include "monty.h"
/**
 * div_node - Adds the top two elements of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode
 */
void div_node(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stack_errors(8, line_number, "div");
		return;
	}

	if ((*stack)->n == 0)
	{
		stack_errors(9, line_number);
		return;
	}
	(*stack) = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * sub_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub_node(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stack_errors(8, line_number, "sub");
		return;
	}
	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * add_node - Adds the top two elements of the stack.
 * @stack: the stack
 * @line_number: line_number
 */
void add_node(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stack_errors(8, line_number, "add");
		return;
	}
	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * swap_node - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stack_errors(8, line_number, "swap");
		return;
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
/**
 * nop - Does nothing
 * @stack: Pointer to a pointer of the stack.
 * @line_number: Interger representing the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* Do nothing */
	(void)stack;
	(void)line_number;
}
