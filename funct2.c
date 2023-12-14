#include "monty.h"

/**
 * nop_fct - Does nothing.
 * @stack: top node of the stack.
 * @line_nb: line number of of the opcode.
 */
void nop_fct(stack_t **stack, unsigned int line_nb)
{
	(void)stack;
	(void)line_nb;
}


/**
 * swap_fct - Swaps the top two elements of the stack.
 * @stack:top node of the stack.
 * @line_nb: line number of of the opcode.
 */
void swap_fct(stack_t **stack, unsigned int line_nb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_nb, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
