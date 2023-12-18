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