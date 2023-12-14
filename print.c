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

/**
 * pstr_fct - Prints a string.
 * @stack:top node of the stack.
 * @line_nb: line number of of the opcode.
 */
void pstr_fct(stack_t **stack, __attribute__((unused))unsigned int line_nb)
{
	int n;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		n = tmp->n;
		if (n <= 0 || n > 127)
			break;
		printf("%c", n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl_fct - Rotates the first node of the stack to the bottom.
 * @stack: top node of the stack.
 * @line_nb: line number of the opcode.
 */
void rotl_fct(stack_t **stack, __attribute__((unused))unsigned int line_nb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr_fct - Rotates the last node of the stack to the top.
 * @stack: top node of the stack.
 * @line_nb: line number of the opcode.
 */
void rotr_fct(stack_t **stack, __attribute__((unused))unsigned int line_nb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

