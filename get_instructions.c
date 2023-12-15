#include "monty.h"

void invalid_instruct(size_t line_numb, char *opcode)
{
    fprintf(stderr, "L%ld: unknown instruction %s\n", line_numb, opcode);
	free(instructions);
	exit(EXIT_FAILURE)
}

void get_instructions(size_t line_numb, char *opcode)
{
    int i = 0; 
    instruction_t instructions[] = {
        {"push", &push},
        {"pall", &pall},
        {NULL, NULL}
    };

for (instructions[i].opcode != NULL)
{
    if (strcmp(instructions[i].opcode, opcode[0]) == 0)
    {
        instructions->opcode = instructions.opcode;
        instructions->f = instructions.&push;
    }
}

    invalid_instruct(line_numb, opcode[0]);
}
