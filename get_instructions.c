#include "monty.h"

/**
 * invalid_instruct - prints error message for invalid instruction
 * @line_numb: line number where the opcode is from
 * @opcode: the instruction
 *
 * Return: nothing
 */

void invalid_instruct(size_t line_numb, char *opcode, instruction_t *inst)
{
	fprintf(stderr, "L%ld: unknown instruction %s\n", line_numb, opcode);
	free(inst);
}

/**
 * get_instruction - gets and instruction
 * @line_numb: line number where the instruct is from
 * @opcode: instruction from stream
 * @inst: pointer to the instruction_t structure
 *
 * Description: sets an array of instruction and function pointers,
 * interate through the array
 * comparing the opcode from stream with the opcode in struct
 * if found sets the instruction struct in main to the opcode in array
 * and sets the function pointer to the function in array
 *
 * Return: nothing
 */

int get_instruction(char *opcode, instruction_t *inst)
{
	int i = 0;
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (; instruct[i].opcode != NULL; i++)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
		{
			inst->opcode = instruct[i].opcode;
			inst->f = instruct[i].f;
			return (1);
		}
	}
	return (-1);
}
