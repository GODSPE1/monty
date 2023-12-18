#include "monty.h"

void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);

/**
 * push - pushes an integer into the stack.
 * @stack: pointer to the stack.
 * @line_num: line number where the push opcode is from
 *
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (value == NULL || isalpha(*value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->n = atoi(value);
	temp->next = *stack;
	temp->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = temp;
	}

	*stack = temp;
}


/**
 * pall - prints all the elements of stack_t list
 * @stack: a pointer to the top node list_t structure
 * @line_num: line number where the pall opcode is from
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;

	(void)line_num;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * add - add two top elements in a stack
 * @stack: a pointer to the top node list_t structure
 * @line_num: line number where the add function is called
 *
 * Return: Nothing.
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp1, *tmp2;
	size_t node_count;

	node_count = count_node(stack, line_num);

	if (node_count < 2)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp1 = *stack;
	tmp2 = tmp1->next;

	tmp2->n = tmp1->n + tmp2->n;

	pop(stack, line_num);

}


/**
 * pop - remove the top element of the stack_t list
 * @stack: a pointer to the top node list_t structure
 * @line_num: line number where the pall opcode is from
 *
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_num)
{
        stack_t *next = NULL;

        if ((*stack)->next == NULL)
        {
                printf("L%d: can't pop an empty stack\n", line_num);
                exit(EXIT_FAILURE);
        }
        next = (*stack)->next->next;
        free((*stack)->next);
        if (next)
                next->prev = *stack;
        (*stack)->next = next;
}

