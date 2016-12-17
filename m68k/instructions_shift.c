#include <stdbool.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instructions_shift.h"
#include "operands.h"

Instruction* gen_shift_instruction(uint16_t opcode, M68k* m, char* name, InstructionFunc func)
{
    bool direction = BIT(opcode, 8);
    bool immediate = BIT(opcode, 5);

    Instruction* i = calloc(1, sizeof(Instruction));
    i->context = m;
    i->name = name;
    i->func = func;
    i->size = operand_size(FRAGMENT(opcode, 7, 6));

    i->operands = calloc(2, sizeof(Operand));

    if (!immediate)
    {
        i->operands[0] = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);
        i->operands[1] = operand_make_data_register(FRAGMENT(opcode, 2, 0), i);
    }
    else
        return NULL;
    // TODO handle immediate mode

    i->operand_count = 2;

    return i;
}

void asl(Instruction* i)
{
    int shift = GET(i->operands[0]);
    int initial = GET(i->operands[1]);
    int shifted_bit = BIT(initial, i->size);

    int result = MASK_ABOVE_INC(initial << shift, i->size);
    SET(i->operands[1], MASK_BELOW(initial, i->size) | result);

    CARRY_SET(i->context, shifted_bit);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, result < 0);
    // TODO EXTENDED_SET();
}

void asr(Instruction* i)
{
    int shift = GET(i->operands[0]);
    int initial = GET(i->operands[1]);
    int shifted_bit = BIT(initial, 0);

    int result = MASK_ABOVE_INC(initial >> shift, i->size);
    SET(i->operands[1], MASK_BELOW(initial, i->size) | result);

    CARRY_SET(i->context, shifted_bit);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, result < 0);
    // TODO EXTENDED_SET();
}

Instruction* gen_asX(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "ASR" : "ASL", direction ? asr : asl);
}

void lsl(Instruction* i)
{
    int shift = GET(i->operands[0]);
    int initial = GET(i->operands[1]);
    int shifted_bit = BIT(initial, i->size);

    int result = MASK_ABOVE_INC(initial << shift, i->size);
    SET(i->operands[1], MASK_BELOW(initial, i->size) | result);

    CARRY_SET(i->context, shifted_bit);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, result < 0);
    // TODO EXTENDED_SET();
}

void lsr(Instruction* i)
{
    int shift = GET(i->operands[0]);
    int initial = GET(i->operands[1]);
    int shifted_bit = BIT(initial, 0);

    int result = MASK_ABOVE_INC(initial >> shift, i->size);
    SET(i->operands[1], MASK_BELOW(initial, i->size) | result);

    CARRY_SET(i->context, shifted_bit);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, result < 0);
    // TODO EXTENDED_SET();
}

Instruction* gen_lsX(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "LSR" : "LSL", direction ? lsr : lsl);
}

void swap(Instruction* i)
{
    int32_t value = GET(i->operands[0]);
    int16_t lo = value & 0xFFFF;
    int16_t hi = value >> 16;
    int32_t result = (lo << 16) | hi;
    SET(i->operands[0], result);

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, 31));
}

Instruction* gen_swap(uint16_t opcode, M68k* m)
{
    Instruction* i = calloc(1, sizeof(Instruction));
    i->context = m;
    i->name = "SWAP";
    i->func = swap;

    i->operands = calloc(2, sizeof(Operand));
    i->operands[0] = operand_make_data_register(FRAGMENT(opcode, 5, 0), i);
    i->operand_count = 1;

    return i;
}
