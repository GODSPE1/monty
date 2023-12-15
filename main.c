#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */

instruction_t *instructions;
int n_tokens;
char *value;

int main(int argc, char **argv)
{
	FILE *file;
	char *line, *delim, *line_cpy;
	size_t len;
	unsigned int line_numb;
	char **opcode;
	size_t read;
	stack_t *stack = NULL;

	line = NULL;
	len = 0;
	line_numb = 1;
	delim = " \n";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	instruction_t *instructions = malloc(sizeof(instruction_t));
	if (instructions == NULL)
	{
		printf("Error: malloc failed");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_cpy = strdup(line);
		if (line_cpy == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		if (strspn(line_cpy, " \t\r\n") == strlen(line_cpy))
		{
			free(line_cpy);
			continue;
		}

		opcode = tokenize(line_cpy, delim);
		/*
		 * printf("____line number = %u____\n", line_numb);
		 */

		if (opcode == NULL)
		{
			free(line_cpy);
			continue;
		}

		value = opcode[1];
		get_instructions(line_numb, opcode[0], instructions);
		instructions->f(&stack, line_numb);

		free(line_cpy);
		line_numb += 1;
		free_mem(opcode);
	}

	free(instructions);
	fclose(file);
	return (0);
}
