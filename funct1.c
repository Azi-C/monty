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

	if (new == NULL || (*new) == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
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
 * @h: stack head
 * @line_nb: line number not used
 */

void pall_fct(stack_t **h, unsigned int line_nb)
{
	stack_t *tmp;
	(void)line_nb;

	if (h == NULL)
		exit(EXIT_FAILURE);
	tmp = *h;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint_fct - prints the value at the top of the stack
 * @h: pointer to a pointer to top node of the stack
 * @line_nb: line number
 */

void pint_fct(stack_t **h, unsigned int line_nb)
{
	if (!h || !(*h))
		err2(6, line_nb);
	printf("%d\n", (*h)->n);
}

/**
 * pop_top_fct - Delete the node in the top
 * @h: pointer to a pointer to top node of the stack
 * @line_nb: line number
 */

void pop_top_fct(stack_t **h, unsigned int line_nb)
{
	stack_t *tmp;

	if (!h || !(*h))
		err2(7, line_nb);

	tmp = *h;
	*h = tmp->next;
	if (*h != NULL)
		(*h)->prev = NULL;

	free(tmp);
}
