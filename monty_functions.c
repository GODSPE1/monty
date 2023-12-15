#include "monty.h"
/**
 * push - pushes an integer into the stack.
 * @stack: pointer to the stack.
 * @value: the value to be pushed onto the stack
 * @line_num: line number where the push is from
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
 * pall_func - prints all the elements of stack_t list
 * @stack_t: a pointer to the top node list_t structure
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
