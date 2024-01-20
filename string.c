#include "monty.h"
/**
 * prints_char - prints the ascii value
 * @stack: pointer to top of stack
 * @line_number: line number
 */
void prints_char(stack_t **stack, unsigned int line_number)
{
	int asci;

	if (stack == NULL || *stack == NULL)
		string_errors(11, line_number);
	asci = (*stack)->n;
	if (asci < 0 || asci > 127)
		string_errors(10, line_number);
	printf("%c\n", asci);
}
/**
 * prints_str - prints a string
 * @stack: top of stack
 * @lnum: line_number
 */
void prints_str(stack_t **stack, __attribute__((unused))unsigned int lnum)
{
	int asci;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		asci = temp->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * rotl - rotated to first node
 * @stack: top of stack
 * @lnum: line_number
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int lnum)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next =  *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr - rotates to last node
 * @stack: top of stack
 * @lnum: line_number
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int lnum)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
