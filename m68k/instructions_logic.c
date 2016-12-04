#include <stdbool.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instruction.h"
#include "instructions_logic.h"
#include "operands.h"

Instruction* gen_logic_instruction(uint16_t opcode, M68k* m, char* name, InstructionFunc* func)
{
    Instruction* i = calloc(1, sizeof(Instruction));
    i->context = m;
    i->name = name;
    i->func = func;

    i->size = operand_size(FRAGMENT(opcode, 7, 6));

    Operand* op1 = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);
    Operand* op2 = operand_make(FRAGMENT(opcode, 5, 0), i);
    int direction = BIT(opcode, 8);

    Operand** operands = calloc(2, sizeof(Operand*));
    operands[direction] = op1;
    operands[(direction + 1) % 2] = op2;

    i->operands = operands;
    i->operand_count = 2;

    return i;
}

void and(Instruction* i)
{
    uint16_t dest = GET(i->operands[1]);
    uint16_t r = GET(i->operands[0]) & dest;
    SET(i->operands[1], MASK_BELOW(dest, i->size) | MASK_ABOVE(r, i->size));
    
    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, r == 0);
    NEGATIVE_SET(i->context, true); // TODO
}

Instruction* gen_and(uint16_t opcode, M68k* m)
{
    return gen_logic_instruction(opcode, m, "AND", and);
}

void eor(Instruction* i)
{
    uint16_t dest = GET(i->operands[1]);
    uint16_t r = GET(i->operands[0]) & dest;
    SET(i->operands[1], MASK_BELOW(dest, i->size) ^ MASK_ABOVE(r, i->size));

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, r == 0);
    NEGATIVE_SET(i->context, true); // TODO
}

Instruction* gen_eor(uint16_t opcode, M68k* m)
{
    return gen_logic_instruction(opcode, m, "EOR", eor);
}

void or (Instruction* i)
{
    uint16_t dest = GET(i->operands[1]);
    uint16_t r = GET(i->operands[0]) | dest;
    SET(i->operands[1], MASK_BELOW(dest, i->size) | MASK_ABOVE(r, i->size));

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, r == 0);
    NEGATIVE_SET(i->context, true); // TODO
}

Instruction* gen_or(uint16_t opcode, M68k* m)
{
    return gen_logic_instruction(opcode, m, "OR", or );
}

void not(Instruction* i)
{
    uint16_t x = GET(i->operands[0]);

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, x == 0);
    NEGATIVE_SET(i->context, true); // TODO
}

Instruction* gen_not(uint16_t opcode, M68k* m)
{
    Instruction* i = calloc(1, sizeof(Instruction));
    i->context = m;
    i->name = "NOT";
    i->func = not;

    i->size = operand_size(FRAGMENT(opcode, 7, 6));

    Operand** operands = calloc(1, sizeof(Operand*));
    i->operands[0] = operand_make(FRAGMENT(opcode, 5, 0), i);
    i->operand_count = 1;

    return i;
}

void tst(Instruction* i)
{
    uint16_t x = ~GET(i->operands[0]);
    SET(i->operands[0], x);

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, x == 0);
    NEGATIVE_SET(i->context, true); // TODO
}

Instruction* gen_tst(uint16_t opcode, M68k* m)
{
    Instruction* i = calloc(1, sizeof(Instruction));
    i->context = m;
    i->name = "TST";
    i->func = tst;

    i->size = operand_size(FRAGMENT(opcode, 7, 6));

    Operand** operands = calloc(1, sizeof(Operand*));
    i->operands[0] = operand_make(FRAGMENT(opcode, 5, 0), i);
    i->operand_count = 1;

    return i;
}
