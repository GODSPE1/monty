#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

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
extern stack_t *stack;
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

extern char *value;

char **tokenize(char *line, char *delim);

void free_mem(char **arg);

void init_instruction(instruction_t *inst, char *opcode, void *func);

void invalid_instruct(size_t line_numb, char *opcode, instruction_t *inst);

int get_instruction(char *opcode, instruction_t *inst);

void push(stack_t **stack, unsigned int line_num);

void pall(stack_t **stack, unsigned int line_num);

void add(stack_t **stack, unsigned int line_num);

void pop(stack_t **stack, unsigned int line_num);

void swap(stack_t **stack, unsigned int line_num);

void mul(stack_t **stack, unsigned int line_num);

void mod(stack_t **stack, unsigned int line_num);

void sub(stack_t **stack, unsigned int line_num);

void _div(stack_t **stack, unsigned int line_num);

void nop(stack_t **stack, unsigned int line_num);

void pchar(stack_t **stack, unsigned int line_num);

void rot1(stack_t **stack, unsigned int line_num);

void pstr(stack_t **stack, unsigned int line_num);

size_t count_node(stack_t **stack);

#endif /* MONTY_H */
