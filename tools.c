#include "monty.h"

/**
 * open_f - opens a file
 * @file_name: the file namepath
 * Return: void
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
 * read_file - reads a file
 * @fd: pointer to file descriptor
 */

void read_f(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - Separates  lines into tokens
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_f(opcode, value, line_number, format);
	return (format);
}

/**
 * find_f - find the function to use
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_nb: line number
 */
void find_f(char *opcode, char *value, int line_nb, int format)
{
	int i;
	int flag;

	instruction_t func_l[] = {
		{"push", push_fct},
		{"pall", pall_fct},
		{"pint", pint_fct},
		{"pop", pop_top},
		{"nop", nop_fct},
		{"swap", swap_fct},
		{"add", add_nodes},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_l[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_l[i].opcode) == 0)
		{
			call_f(func_l[i].f, opcode, value, line_nb, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, line_nb, opcode);
}


/**
 * call_f - Calls the fuction to use
 * @fct: Pointer to the function 
 * @op: string representing the opcode
 * @val: string reprenting numeric value
 * @line_nb: line numeber for the instruction.
 * @format: Format specifier.
 */
void call_f(op_func fct, char *op, char *val, int line_nb, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
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
