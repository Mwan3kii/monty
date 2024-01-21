#include "monty.h"
/**
 * mod_node - adds to stack
 * @stack: the stack
 * @line_number: line number
 */
void mod_node(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stack_errors(8, line_number, "mod");
		return;
	}
	if ((*stack)->n == 0)
	{
		stack_errors(9, line_number);
		return;
	}
	(*stack) = (*stack)->next;
	result = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mul_node - adds to stack
 * @stack: the stack
 * @line_number: the interger with the line number
 */
void mul_node(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stack_errors(8, line_number, "mul");
		return;
	}
	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
