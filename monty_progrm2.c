#include "monty.h"
/**
 * find_funct - finds the function to be called
 * @opcode: opcode
 * @str_num: argument of opcode
 * @l_num: line number
 * @frmt: format specifier
 * Return: void
 */
void find_funct(char *opcode, char *str_num, int l_num, int frmt)
{
	int k;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", prints_stack},
		{"pint", prints_top},
		{"pop", pops_top},
		{"nop", nop},
		{"swap", swap_node},
		{"add", add_node},
		{"sub", sub_node},
		{"div", div_node},
		{"mul", mul_node},
		{"mod", mod_node},
		{"pchar", prints_char},
		{"pstr", prints_str},
		{"rotl", rotl},
		{"rotr", rotr},
	};
	if (opcode[0] == '#')
		return;
	for (flag = 1, k = 0; func_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, func_list[k].opcode) == 0)
		{
			call_funct(func_list[k].f, opcode, str_num, l_num, frmt);
			flag = 0;
		}
	}
		if (flag == 1)
			errors(3, l_num, opcode);
}
/**
 * call_funct - calls the func required
 * @funct: pointer to function to be called
 * @op: opcode
 * @strnum: string in numeral value
 * @l_num: line_number
 * @frmt: format specifier
 * if 1 nodes will be entered
 */
void call_funct(op_funct funct, char *op, char *strnum, int l_num, int frmt)
{
	stack_t *nod;
	int flag;
	int j;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (strnum != NULL && strnum[0] == '-')
		{
			strnum = strnum + 1;
			flag = -1;
		}
		if (strnum == NULL)
			errors(5, l_num);
		for (j = 0; strnum[j] != '\0'; j++)
		{
			if (isdigit(strnum[j]) == 0)
				errors(5, l_num);
		}
		nod = creates_nodes(atoi(strnum) * flag);
		if (frmt == 0)
			funct(&nod, l_num);
		if (frmt == 1)
			add_to_stack(&nod, l_num);
	}
	else
		funct(&h, l_num);
}
