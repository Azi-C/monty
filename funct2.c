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
 * add_fct - Adds the top two elements of the stack.
 * @stack: top node of the stack.
 * @line_nb: line number of of the opcode.
 */
void add_fct(stack_t **stack, unsigned int line_nb)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_nb, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_fct - subs the two top elements
 * @stack: top node of the stack
 * @line_nb: line number
 */

void sub_fct(stack_t **stack, unsigned int line_nb)
{
	int rslt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_nb, "sub");

	(*stack) = (*stack)->next;
	rslt = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = rslt;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_fct - divs the two top elements
 * @stack: top node of the stack
 * @line_nb: line number
 */

void div_fct(stack_t **stack, unsigned int line_nb)
{
	int rslt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_nb, "div");

	(*stack) = (*stack)->next;
	rslt = (*stack)->n / (*stack)->prev->n;
      	(*stack)->n = rslt;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
