#include "monty.h"

void init_instruction(instruction_t *inst, char *opcode, void *func)
{
    inst->opcode = strdup(opcode);
    inst->f = func;
}
