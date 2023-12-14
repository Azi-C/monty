#include "monty.h"

/**
 * mul_fct - multiplates the top two elements
 * @stack: top node of the stack.
 * @line_nb: number of of the opcode.
 */
void mul_fct(stack_t **stack, unsigned int line_nb)
{
	int rslt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_nb, "mul");

	(*stack) = (*stack)->next;
	rslt = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = rslt;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_fct - mod between the top two elements of the stack.
 * @stack: top node of the stack.
 * @line_nb: line number of of the opcode.
 */
void mod_fct(stack_t **stack, unsigned int line_nb)
{
	int rslt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err2(8, line_nb, "mod");


	if ((*stack)->n == 0)
		err2(9, line_nb);
	(*stack) = (*stack)->next;
	rslt = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = rslt;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
