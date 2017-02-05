#include <stdlib.h>

#include "instruction.h"
#include "m68k.h"
#include "operands.h"

int add(Instruction* i)
{
    FETCH_EAE(i->src);
    FETCH_EAE(i->dst);

    uint32_t a = GETE(i->dst);
    uint32_t b = GETE(i->src);
    SETE(i->dst, a + b);

    uint32_t result = GETE(i->dst);
    CARRY_SET(i->context, CHECK_CARRY_ADD(a, b, i->size));
    OVERFLOW_SET(i->context, CHECK_OVERFLOW_ADD(a, b, i->size));
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1));
    EXTENDED_SET(i->context, CARRY(i->context));

    return 0;
}

Instruction* gen_add(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "ADD", add);

    i->size = operand_size(FRAGMENT(opcode, 7, 6));

    Operand* reg = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);
    Operand* ea = operand_make(FRAGMENT(opcode, 5, 0), i);

    int direction = BIT(opcode, 8);
    if (direction == 0)
    {
        i->src = ea;
        i->dst = reg;
    }
    else
    {
        i->src = reg;
        i->dst = ea;
    }

    return i;
}

int addq(Instruction* i)
{
    // Extract the quick value, 0 represents 8
    uint32_t quick = GETE(i->src);
    if (quick == 0)
        quick = 8;

    uint32_t initial = FETCH_EA_AND_GETE(i->dst);
    SETE(i->dst, initial + quick);

    uint32_t result = GETE(i->dst);
    CARRY_SET(i->context, CHECK_CARRY_ADD(initial, quick, i->size));
    OVERFLOW_SET(i->context, CHECK_OVERFLOW_ADD(initial, quick, i->size));
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1));

    return 0;
}

Instruction* gen_addq(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "ADDQ", addq);
    i->size = operand_size(FRAGMENT(opcode, 7, 6));
    i->src = operand_make_value(FRAGMENT(opcode, 11, 9), i);
    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i);
    return i;
}

int clr(Instruction* i)
{
    FETCH_EA_AND_SETE(i->src, 0);

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, true);
    NEGATIVE_SET(i->context, false);

    return 0;
}

Instruction* gen_clr(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "CLR", clr);
    i->size = operand_size(FRAGMENT(opcode, 7, 6));
    i->src = operand_make(FRAGMENT(opcode, 5, 0), i);
    return i;
}

int cmp(Instruction* i)
{
    uint32_t a = GETE(i->dst);
    uint32_t b = FETCH_EA_AND_GETE(i->src);

    CARRY_SET(i->context, CHECK_CARRY_SUB(a, b, i->size));
    OVERFLOW_SET(i->context, CHECK_OVERFLOW_SUB(a, b, i->size));
    ZERO_SET(i->context, a == b);
    NEGATIVE_SET(i->context, BIT(a - b, i->size - 1));

    return 0;
}

Instruction* gen_cmp(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "CMP", cmp);
    i->size = operand_size(FRAGMENT(opcode, 7, 6));
    i->src = operand_make(FRAGMENT(opcode, 5, 0), i);
    i->dst = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);
    return i;
}

int ext(Instruction* i)
{
    int x = GETE(i->src);

    uint32_t extended;
    switch (i->size) {
    case Word:
        extended = SIGN_EXTEND_B(x);
        break;
    case Long:
        extended = SIGN_EXTEND_W(x);
        break;
    }

    SETE(i->src, extended);

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, extended == 0);
    NEGATIVE_SET(i->context, BIT(extended, i->size - 1) == 1);

    return 0;
}

Instruction* gen_ext(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "EXT", ext);
    i->size = operand_sign_extension(FRAGMENT(opcode, 8, 6));
    i->src = operand_make_data_register(FRAGMENT(opcode, 3, 0), i);
    return i;
}

int muls(Instruction* i)
{
    // TODO SET(i->src, GET(i->src) * GET(i->dst));

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false); // TODO
    ZERO_SET(i->context, true); // TODO
    NEGATIVE_SET(i->context, false); // TODO
                                     // TODO EXT

    return 0;
}

Instruction* gen_muls(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "MULS", muls);
    i->size = operand_size(FRAGMENT(opcode, 7, 6));
    i->src = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);
    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i);
    return i;
}

int mulu(Instruction* i)
{
    // TODO SET(i->src, GET(i->src) * GET(i->dst));

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false); // TODO
    ZERO_SET(i->context, true); // TODO
    NEGATIVE_SET(i->context, false); // TODO
                                     // TODO EXT

    return 0;
}

Instruction* gen_mulu(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "MULU", mulu);
    i->size = operand_size(FRAGMENT(opcode, 7, 6));
    i->src = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);
    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i);
    return i;
}

int subq(Instruction* i)
{
    // Extract the quick value, 0 represents 8
    uint32_t quick = GETE(i->src);
    if (quick == 0)
        quick = 8;

    uint32_t initial = FETCH_EA_AND_GETE(i->dst);
    SETE(i->dst, initial - quick);

    CARRY_SET(i->context, CHECK_CARRY_SUB(initial, quick, i->size));
    OVERFLOW_SET(i->context, CHECK_OVERFLOW_SUB(initial, quick, i->size));
    ZERO_SET(i->context, initial == quick);
    NEGATIVE_SET(i->context, BIT(initial - quick, i->size - 1));

    return 0;
}

Instruction* gen_subq(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "SUBQ", subq);
    i->size = operand_size(FRAGMENT(opcode, 7, 6));
    i->src = operand_make_value(FRAGMENT(opcode, 11, 9), i);
    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i);
    return i;
}
