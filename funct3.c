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
