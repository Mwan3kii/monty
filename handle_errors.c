#include "monty.h"
/**
 * errors - func handles errors
 * @handle_errors: parameter
 */
void errors(int handle_errors, ...)
{
	va_list args;
	char *opcode;
	int lnum;

	va_start(args, handle_errors);
	switch (handle_errors)
	{
		case 1:
			fprintf(stderr, "Usage: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(args, char *));
			break;
		case 3:
			lnum = va_arg(args, int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lnum, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * stack_errors - handles errors for the stack
 * @handle_errors: parameter
 * @int: the interger
 */
void stack_errors(int handle_errors, ...)
{
	va_list args;
	char *opcode;
	int lnum;

	va_start(args, handle_errors);
	switch (handle_errors)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(args, int));
			break;
		case 8:
			lnum = va_arg(args, unsigned int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: cant %s, stack too short\n", lnum, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * string_errors - handles string errors
 * @handle_errors: parameter
 */
void string_errors(int handle_errors, ...)
{
	va_list args;
	int lnum;

	va_start(args, handle_errors);
	lnum = va_arg(args, int);
	switch (handle_errors)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lnum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lnum);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
