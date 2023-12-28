/**
 * count_nodes - count number of nodes in the list.
 * @stack: a pointer to the stack
 * @line_num: line number where the push opcode is from
 *
 */
size_t count_node(stack_t **stack, unsigned int line_num)
{
	stack_t *current = (*stack);
	size_t count = 0;

	if (current == NULL)
	{
		printf("Empty list");
		return (0);
	}
	while (current != NULL)
	{
		current = current->next;
		count++;
	}

	return (count);
}
