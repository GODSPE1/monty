#include "monty.h"
/**
 * push - pushes an integer into the stack.
 * @stack: pointer to the stack.
 * @value: the value to be pushed onto the stack
 * @line_num: line number where the push is from
 */
void push(stack_t **stack, char *value, size_t line_num)
{
    if (value == NULL || !is_integer(value))
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
 * is_integer - checks if a string is a valid integer.
 * @value: the character to check.
 *
 * Return: 0
 */
void is_integer(int value)
{
	int i;


	if (arg == NULL)
		return (1);
	i = 0;
	while (arg[i] != '\0')
	{
		if (isalpha(arg[i]))
			return (1);
		i++;
	}
	return (0);

}
