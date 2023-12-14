#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_fct)(stack_t **, unsigned int);

void push_fct(stack_t **new, unsigned int line_nb);
void pall_fct(stack_t **h, unsigned int line_nb);
void pint_fct(stack_t **h, unsigned int line_nb);
void err(int err_code, ...);
void err2(int err_code, ...);
void free_nodes(void);
void pop_top_fct(stack_t **h, unsigned int line_nb);
void call(op_fct fct, char *opcode, char *val, int line_nb, int format);
void find(char *opcode, char *val, int line_nb, int format);
void open_f(char *file_name);
void read_f(FILE *fd);
void add_to_queue(stack_t **, unsigned int);
stack_t *create_node(int n);
int parse_line(char *, int, int);
void string_err(int err_code, ...);

#endif
