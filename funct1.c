#include "monty.h"

/**
 * push_fct - Adds a node in the beginning
 * @new: pointer to the node to add
 * @line_nb: line number not used
 */

void push_fct(stack_t **new, unsigned int line_nb)
{
	stack_t *tmp;
	(void)line_nb;

	if (!new || !(*new))
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new;
		return;
	}

	tmp = head;
	head = *new;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * pall_fct - Prints a stack
 * @head: stack head
 * @line_nb: line number not used
 */

void pall_fct(stack_t **head, unsigned int line_nb)
{
	stack_t *tmp;
	(void)line_nb;

	if (!head)
		exit(EXIT_FAILURE);
	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
