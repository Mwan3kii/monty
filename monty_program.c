#include "monty.h"
/**
 * opens_file - opens a file
 * @file: the name of the file
 */
void opens_file(char *file)
{
	FILE *fd = fopen(file, "r");

	if (file == NULL || fd == NULL)
		errors(2, file);
	reads_file(fd);
	fclose(fd);
}
/**
 * reads_file - reads a file
 * @fd: the file descriptor
 */
void reads_file(FILE *fd)
{
	int lnum, frmt = 0;
	char *buff = NULL;
	size_t len = 0;

	for (lnum = 1; getline(&buff, &len, fd) != -1; lnum++)
	{
		frmt = parses_line(buff, lnum, frmt);
	}
	free(buff);
}
/**
 * parses_line - func that separates in tokens
 * @buff: the buffer
 * @line_number: the line number
 * @frmt: storage format
 *
 * Return: 0 if the opcode is stack
 * 1 if it is a queue
 */
int parses_line(char *buff, int line_number, int frmt)
{
	char *opcode, *str_num;
	const char *delim = "\n";

	if (buff == NULL)
		errors(4);
	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (frmt);
	str_num = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_funct(opcode, str_num, line_number, frmt);
	return (frmt);
}
