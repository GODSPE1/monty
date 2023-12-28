#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv);

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */

char *value;

int main(int argc, char **argv)
{
	FILE *file;
	char *line, *delim, *line_cpy;
	size_t len;
	unsigned int line_numb;
	char **opcode;
	stack_t *stack = NULL;
	instruction_t *instruction;

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

	instruction = malloc(sizeof(instruction_t));
	if (instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	while ((getline(&line, &len, file)) != -1)
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
		}
		else
		{

			opcode = tokenize(line_cpy, delim);

			/*
			 * printf("____line number = %u____\n", line_numb);
			 */

			if (opcode == NULL)
			{
				free(line_cpy);
			}
			else
			{
				value = opcode[1];
				if (get_instruction(opcode[0], instruction) != 1)
				{
					free(line);
					free(line_cpy);
					invalid_instruct(line_numb, opcode[0], instruction);
					free_mem(opcode);
					fclose(file);
					exit(EXIT_FAILURE);
				}

				instruction->f(&stack, line_numb);
			}

			line_numb += 1;
			free(line_cpy);
			free_mem(opcode);
		}
	}

	free(line);
	free(instruction);
	fclose(file);
	return (0);
}
