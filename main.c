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
	char *line, *delim;
	size_t len, line_numb;
	char **opcode;
	size_t read;


	size_t i;
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

	while (getline(&line , &len, file) != -1)
	{
		opcode = tokenize(line, delim);
		printf("____line number = %ld____\n", line_numb);
		instructions = malloc(sizeof(instruction_t));

		if (instructions == NULL)
		{
			printf("Error: malloc failed");
			free(instructions);
		}
		
		
		printf("opcode = %s \n",opcode[0]);
		printf("argument = %s \n",opcode[1]);

		if (instructions->f != NULL)
			instructions->f(stack, opcode[1]);
		line_numb += 1;

		i = 0;
		free(instructions);
		free_mem(opcode);
	}
	fclose(file);
	return (0);
}
