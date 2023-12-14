#include "monty.h"

/**
 * open_f - opens a file
 * @file_name: the file name
 */

void open_f(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_f(fd);
	fclose(fd);
}

/**
 * read_f - read a file
 * @fd: pointer to the file
 */

void read_f(FILE *fd)
{
	int line_nb;
	int format = 0;
	char *buffer = NULL;
	size_t l = 0;

	for (line_nb = 1; getline(&buffer, &l, fd) != -1; line_nb++)
		format = parse_line(buffer, line_nb, format);
	free(buffer);
}

/**
 * parse_line - seperates lines into tokens
 * @buffer: line from the file
 * @line_nb: line number
 * @format: storage format
 * Return: 0 if the opcode is stack, 1 if it is queue
 */

int parse_line(char *buffer, int line_nb, int format)
{
	char *op;
	char *value;
	const char *d = "\n";

	if (!buffer)
		err(4);
	op = strtok(buffer, d);

	if (!op)
		return (format);

	value = strtok(NULL, d);
	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	find(op, value, line_nb, format);
	return (format);
}

/**
 * find - find the function to use
 * @opcode: opcode
 * @val: argument of opcode
 * @format: storage format
 * @line_nb: line number
 */

void find(char *opcode, char *val, int line_nb, int format)
{
	int i;
	int flag;

	instruction_t fcts[] = {
		{"push", push_fct},
		{"pall", pall_fct},
		{"pint", pint_fct},
		{"pop", pop_top_fct},
		{"swap", swap_fct},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; fcts[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, fcts[i].opcode) == 0)
		{
			call(fcts[i].f, opcode, val, line_nb, format);
			flag = 0;
		}
	}

	if (flag == 1)
		err(3, line_nb, opcode);
}

/**
 * call - calls the right function
 * @fct: pointer to the fct
 * @opcode: opcode
 * @val: numeric value
 * @line_nb: line number
 * @format: storage format
 */

void call(op_fct fct, char *opcode, char *val, int line_nb, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val++;
			flag = -1;
		}
		if (!val)
			err(5, line_nb);

		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, line_nb);
		}

		node = create_node(atoi(val) * flag);
		if (format == 0)
			fct(&node, line_nb);
		if (format == 1)
			add_to_queue(&node, line_nb);
	}
	else
		fct(&head, line_nb);
}
