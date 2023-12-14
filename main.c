#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: arguments
 * @argv: list of arguments
 * Return: 0 Always (Success)
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - creates a node
 * @n: number to add
 * Return: pointer to the node if sucess, NULL otherwise
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - frees  nodes
 */

void free_nodes(void)
{
	stack_t *tmp;

	if (!head)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - adds a node to the queue
 * @new: pointer to the node
 * @line_nb: line number
 */

void add_to_queue(stack_t **new, __attribute__((unused))unsigned int line_nb)
{
	stack_t *tmp;

	if (!new || *new == NULL)
		exit(EXIT_FAILURE);

	if (!head)
	{
		head = *new;
		return;
	}

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp-> next = *new;
	(*new)->prev = tmp;
}
