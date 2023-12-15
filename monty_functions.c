#include "monty.h"
/**
 * push - pushes an integer into the stack.
 * @stack: pointer to the stack.
 * @value: the value to be pushed onto the stack
 * @line_num: line number where the push is from
 */

void push(stack_t **stack, size_t line_num)
{
    char *value;

    if (isalpha(atoi(value)))
    {
        dprintf(2, "L%lu: usage: push integer\n", line_num);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = malloc(sizeof(stack_t));

    if (temp == NULL)
    {
        dprintf(2, "Error: malloc failed\n");
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
void pall(stack_t **stack, size_t line_num)
{
	(void)line_num;
	stack_t *h;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
