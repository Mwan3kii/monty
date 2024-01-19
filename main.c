#include "monty.h"
stack_t *h = NULL;

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 when success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opens_file(argv[1]);
	free_nodes();
	return (0);
}
/**
 * creates_nodes - function to create nodes
 * @n: interger to store
 * Return: node
 */
stack_t *creates_nodes(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
/**
 * free_nodes - function that frees the nodes
 */
void free_nodes(void)
{
	stack_t *h = NULL;
	stack_t *temp;

	if (h == NULL)
		return;
	while (h != NULL)
	{
		temp = h;
		h = h->next;
		free(temp);
	}
}
/**
 * add_to_queue - adds to a creates queue
 * @new_node: node to add to queue
 * @lnum: the line number
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int lnum)
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
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}
