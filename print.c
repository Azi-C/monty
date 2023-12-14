#include "monty.h"

/**
 * pchar_fct - printd the ascii val
 * @stack: top node of the stack.
 * @line_nb: line number of of the opcode
 */

void pchar_fct(stack_t **stack, unsigned int line_nb)
{
	int n;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_nb);

	n = (*stack)->n;
	if (n < 0 || n > 127)
		string_err(10, line_nb);
	printf("%c\n", n);
}
