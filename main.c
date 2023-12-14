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
	char **opcode_array;
	size_t read;

	size_t i;
	line = NULL;
	len = 0;
	line_numb = 1;
	delim = " ";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line , &len, file) != -1)
	{
		opcode_array = tokenize(line, delim);
		printf("____line number = %ld____\n", line_numb);
		/*
		 * for (i = 0; opcode_array[i] != NULL; i++)
		 * {
		 * 	printf("opcode = %s \n",opcode_array[i]);
		 * }
		 */
		printf("opcode = %s \n",opcode_array[0]);
		printf("argument = %s \n",opcode_array[1]);
		line_numb += 1;

		i = 0;
		free_mem(opcode_array);
	}
	fclose(file);
	return (0);
}
