#include "monty.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line, command;
	size_t size,
	       size_t line_numb;
	stack_t *stack;
	size_t read;

	line = NUL;
	size = 0;
	stack = NULL;
	line_numb = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = open (argv[1], "r");
	if (file == NULL)
		file_open_error(argv);
	read = getline (&line , size, file);
	while (read != -1)
	{
		command = find_command(line, &stack, line_numb);
		if (strcmp(command, "op"))
			use-command(command, &tack, &line_numb);

		if (ret_and_q.opcode_return != 0)
		{
			free_exit(&line, file, stack);
		}
		line_numb++;
		read = getline(&line, size, file);
	}

	free_stack;
	free(line);
	fclose(file);
	return (0);
}
