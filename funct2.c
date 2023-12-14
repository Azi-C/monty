#include "monty.h"

/**
 * swap_fct - swaps the top two elements
 * @h: head of the stack
 * @line_nb: line number
 */

void swap_fct(stack_t **h, unsigned int line_nb)
{
	stack_t *tmp;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
		err2(8, line_nb, "swap");
	tmp = (*h)->next;
	(*h)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *h;

	tmp->next = *h;
	(*h)->prev = tmp;
	tmp->prev = NULL;
	*h = tmp;
}

/**
 * nop_fct - does nothing
 * @h: head of the stack
 * @line_nb: line number
 */
void nop_fct(stack_t **stack, unsigned int line_nb)
{
	(void)h;
	(void)line_nb;
}
