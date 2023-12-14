#include "monty.h"

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
