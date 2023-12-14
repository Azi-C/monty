#include "monty.h"


/**
 * push_fct - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_nb: line number of of the opcode.
 */
void push_fct(stack_t **new_node, __attribute__((unused))unsigned int line_nb)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * pall_fct - print all nodes of a stack.
 * @stack: top node of the stack.
 * @line_nb: line number of  the opcode.
 */
void pall_fct(stack_t **stack, unsigned int line_nb)
{
	stack_t *tmp;

	(void) line_nb;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the of top of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_nb: line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_nb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		err2(7, line_nb);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pint_fct - Prints the top node of the stack.
 * @stack: top node of the stack.
 * @line_nb: line number of the opcode.
 */
void pint_fct(stack_t **stack, unsigned int line_nb)
{
	if (stack == NULL || *stack == NULL)
		err2(6, line_nb);
	printf("%d\n", (*stack)->n);
}
