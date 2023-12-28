#include "monty.h"
void nop(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void rot1(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);

/**
 * nop - Computes nothing
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the swap function is called
 *
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * pchar - Prints the character in the top two elements of the stack
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the swap function is called
 *
 * Return: Nothing.
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprint(stderr, "L%u: can't pchar, stack empty", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstr - prints the string contained in a stack_t linked list
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the swap function is called
 *
 * Return: Nothing.
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void)stack;
	(void)line_num;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n  < 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rot1 - rotates the stack to start from the top
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the swap function is called
 *
 * Return: Nothing.
 */
void rot1(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	temp1 = (*stack)->next;
	temp2 = temp1->next;
	(*stack)->next = temp2;
	while (temp2)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp1;
	temp1->next = NULL;
	temp1->prev = temp2;
}
