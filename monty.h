#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *h;
typedef void (*op_funct)(stack_t **, unsigned int);

void errors(int handle_errors, ...);
void stack_errors(int handle_errors, ...);
void opens_file(char *file);
void string_errors(int handle_errors, ...);
void reads_file(FILE *fd);
int parses_line(char *buff, int line_number, int frmt);
void find_funct(char *opcode, char *str_num, int l_num, int frmt);
void call_funct(op_funct, char *, char *, int, int);
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int lnum);
void prints_str(stack_t **stack, __attribute__((unused))unsigned int lnum);
void pops_top(stack_t **stack, unsigned int line_number);
void prints_stack(stack_t **stack, unsigned int line_number);
void prints_top(stack_t **stack, unsigned int line_number);
void mod_node(stack_t **stack, unsigned int line_number);
void mul_node(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, __attribute__((unused))unsigned int lnum);
void rotr(stack_t **stack, __attribute__((unused))unsigned int lnum);
void prints_str(stack_t **stack, unsigned int line_number);
void prints_char(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, unsigned int line_number);
void sub_node(stack_t **stack, unsigned int line_number);
void div_node(stack_t **stack, unsigned int line_number);
stack_t *creates_nodes(int n);
void free_nodes(void);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int lnum);
void swap_node(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int len_chars(FILE *);

#endif
