#include "monty.h"

/**
 * err2 - handles errors
 * @err_code: the error codes are:
 * (6) => stack empty for pint
 * (7) => stack empty for pop
 * (8) => stack too short for operation
 * (9) => dividion by zero
 */

void err2(int err_code, ...)
{
	va_list ag;
	char *operation;
	int line_nb;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
