#include "monty.h"
void swap(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void div(stack_t **stack, unsigned int line_num);

/**
 * swap - swaps the top two elements of the stack
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the swap function is called
 *
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp1, *tmp2;
     size_t count;

count = count_node(stack, line_num);

    if (count < 2)
    {
        printf("L%d: can't swap, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    tmp1 = (*stack)->next;
    tmp2 = tmp1->next;

    if (tmp2)
        tmp2->prev = tmp1;

    tmp1->next = tmp2;
    tmp1->prev = tmp2;
    tmp2->next = tmp1;
    tmp2->prev = NULL;

    *stack = tmp2;
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the mul opcode is from
 *
 * Return: Nothing.
 */
void mul(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp1, *tmp2;
     size_t count;

count = count_node(stack, line_num);

    if ((*stack)->next == NULL || (*stack)->next->next == NULL || count < 2)
    {
        printf("L%d: can't mul, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    tmp1 = (*stack)->next;
    tmp2 = tmp1->next;

    tmp2->n = tmp1->n * tmp2->n;

    pop(stack, line_num);
    count -= 1;
}

/**
 * mod - calculates the modulus of the second value from the top
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the mod opcode is from
 *
 * Return: Nothing.
 */
void mod(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp1, *tmp2;
    size_t count;

count = count_node(stack, line_num);

    if ((*stack)->next == NULL || (*stack)->next->next == NULL || count < 2)
    {
        printf("L%d: can't mod, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    tmp1 = (*stack)->next;
    tmp2 = tmp1->next;

    tmp1->n = tmp2->n % tmp1->n;

    pop(stack, line_num);
    count -= 1;
}

/**
 * div - divides the top two elements of the stack
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the div opcode is from
 *
 * Return: Nothing.
 */
void div(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp1, *tmp2;
 size_t count;

count = count_node(stack, line_num);
    if (count < 2)
    {
        printf("L%d: can't div, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    tmp1 = (*stack)->next;
    tmp2 = tmp1->next;

    if (tmp1->n == 0)
    {
        printf("L%d: division by zero\n", line_num);
        exit(EXIT_FAILURE);
    }

    tmp2->n = tmp2->n / tmp1->n;

    pop(stack, line_num);
    count -= 1;
}

/**
 * sub - subtract the top two elements of the stack
 * @stack: a pointer to the top node stack_t structure
 * @line_num: line number where the div opcode is from
 *
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp1, *tmp2;
    size_t count;

count = count_node(stack, line_num);
    if (count < 2)
    {
        fprintf("L%d: can't sub, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    tmp1 = (*stack)->next;
    tmp2 = tmp1->next;

    if (tmp1->n == 0)
    {
        ;
    }

    tmp2->n = tmp2->n - tmp1->n;

    pop(stack, line_num);
    count -= 1;
}
