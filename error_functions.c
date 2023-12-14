#include "monty.h"

/**
 * err - handles errors
 * @err_code: the error codes are:
 * (1) => any file or more than one are given
 * (2) => file can not be opened or read
 * (3) => file contains an invalid instruction
 * (4) => program is unabled to malloc more memory
 * (5) => the parameter passed to "push" is not int
 */

void err(int err_code, ...)
{
	va_list ag;
	char *opcode;
	int line_nb;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line_nb = va_arg(ag, int);
			opcode = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nb, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

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
	char *opcode;
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
		case 8:
			line_nb = va_arg(ag, unsigned int);
			opcode = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_nb, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors
 * @err_code: the error codes are:
 * (10) => number outside ASCII bounds
 * (11) => stack empty
 */

void string_err(int err_code, ...)
{
	va_list ag;
	int line_nb;

	va_start(ag, err_code);
	line_nb = va_arg(ag, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_nb);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_nb);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
