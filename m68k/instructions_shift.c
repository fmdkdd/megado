#include <stdbool.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instruction.h"
#include "m68k.h"
#include "operands.h"

Instruction* gen_shift_instruction(uint16_t opcode, M68k* m, char* name, InstructionFunc func)
{
    Instruction* i = instruction_make(m, name, func);
    i->size = operand_size(FRAGMENT(opcode, 7, 6));
    i->dst = operand_make_data_register(FRAGMENT(opcode, 2, 0), i);

    bool reg = BIT(opcode, 5);
    if (reg)
        i->src = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);
    else
        i->src = operand_make_value(FRAGMENT(opcode, 11, 9), i);

    return i;
}

void asr(Instruction* i)
{
    uint32_t initial = GET(i->dst);
    uint8_t shift = GET(i->src);
    uint32_t shifted_in = BIT(initial, i->size - 1) ? MASK_BELOW(0xFFFFFFFF, i->size - shift) : 0;
    SET(i->dst, initial >> shift | shifted_in);

    uint32_t result = GET(i->dst);
    CARRY_SET(i->context, BIT(initial, 0)); // TODO not sure, should be last bit shifter out?
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);
    EXTENDED_SET(i->context, CARRY(i->context));
}

void lsl(Instruction* i)
{
    uint32_t initial = GET(i->dst);
    SET(i->dst, initial << GET(i->src));

    uint32_t result = GET(i->dst);
    CARRY_SET(i->context, BIT(initial, i->size - 1)); // TODO not sure, should be last bit shifter out?
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);
    EXTENDED_SET(i->context, CARRY(i->context));
}

void lsr(Instruction* i)
{
    uint32_t initial = GET(i->dst);
    SET(i->dst, initial >> GET(i->src));

    uint32_t result = GET(i->dst);
    CARRY_SET(i->context, BIT(initial, 0)); // TODO not sure, should be last bit shifter out?
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);
    EXTENDED_SET(i->context, CARRY(i->context));
}

Instruction* gen_asd(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "ASL" : "ASR", direction ? lsl : asr); // ASL = LSL
}

Instruction* gen_lsd(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "LSL" : "LSR", direction ? lsl : lsr);
}

void rol(Instruction* i)
{
    uint32_t initial = GET(i->dst);
    int rotation = GET(i->src) % i->size;

    if (rotation > 0)
        SET(i->dst, initial << rotation | FRAGMENT(initial, i->size - 1, i->size - rotation));

    // TODO what if rot = 0?
    uint32_t result = GET(i->dst);
    CARRY_SET(i->context, BIT(initial, i->size - rotation));
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);
}

void ror(Instruction* i)
{
    uint32_t initial = GET(i->dst);
    int rotation = GET(i->src) % i->size;

    if (rotation > 0)
        SET(i->dst, initial >> rotation | FRAGMENT(initial, rotation - 1, 0) << (i->size - rotation));

    uint32_t x = initial >> rotation;
    uint32_t y = FRAGMENT(initial, rotation - 1, 0);
    uint32_t z = FRAGMENT(initial, rotation - 1, 0) << (i->size - rotation);

    // TODO what if rot = 0?
    uint32_t result = GET(i->dst);
    CARRY_SET(i->context, BIT(initial, i->size - rotation));
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);
}

Instruction* gen_rod(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "ROL" : "ROR", direction ? rol : ror);
}

void swap(Instruction* i)
{
    int32_t value = GET(i->src);
    int16_t lo = value & 0xFFFF;
    int16_t hi = value >> 16;
    int32_t result = (lo << 16) | hi;
    SET(i->src, result);

    CARRY_SET(i->context, false);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, 31));
}

Instruction* gen_swap(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "SWAP", swap);
    i->size = Long;
    i->src = operand_make_data_register(FRAGMENT(opcode, 5, 0), i);
    return i;
}
