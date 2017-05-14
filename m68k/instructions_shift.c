#include <stdbool.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "cycles.h"
#include "instruction.h"
#include "m68k.h"
#include "operands.h"

// TODO check all timings

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

    i->base_cycles = i->size == Long ? 8 : 6;

    return i;
}

Instruction* gen_shift_memory_instruction(uint16_t opcode, M68k* m, char* name, InstructionFunc func)
{
    Instruction* i = instruction_make(m, name, func);
    i->size = Word;
    i->src = operand_make_value(1, i); // The shift count is always 1
    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i);
    
    if (instruction_is_valid(i, true, true))
        i->base_cycles = 8 + cycles_ea_calculation_table[i->src->type][i->dst->type];

    return i;
}

int asr(Instruction* i)
{
    uint32_t initial = FETCH_EA_AND_GET(i->dst);

    uint8_t shift = FETCH_EA_AND_GET(i->src);
    if (shift == 0)
        shift = 8;

    if (shift > 0)
    {
        uint32_t shifted_in = BIT(initial, i->size - 1) ? MASK_BELOW(0xFFFFFFFF, i->size - shift) : 0;
        SET(i->dst, initial >> shift | shifted_in);
        
        uint8_t last_shifted_out = shift > i->size ? 0 : BIT(initial, shift - 1);
        CARRY_SET(i->context, last_shifted_out);
        EXTENDED_SET(i->context, last_shifted_out);
    }

    uint32_t result = GET(i->dst);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);

    return 2 * shift;
}

int lsl(Instruction* i)
{
    uint32_t initial = FETCH_EA_AND_GET(i->dst);

    uint8_t shift = FETCH_EA_AND_GET(i->src);
    if (shift == 0)
        shift = 8;

    if (shift > 0) // TODO always > 0!!
    {
        SET(i->dst, initial << shift);

        uint8_t last_shifted_out = shift > i->size ? 0 : BIT(initial, i->size - shift);
        EXTENDED_SET(i->context, last_shifted_out);
        CARRY_SET(i->context, last_shifted_out);
    }

    uint32_t result = GET(i->dst);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);

    return 2 * shift;
}

int lsr(Instruction* i)
{
    uint32_t initial = FETCH_EA_AND_GET(i->dst);

    uint8_t shift = FETCH_EA_AND_GET(i->src);
    if (shift == 0)
        shift = 8;

    if (shift > 0) // TODO always > 0!!
    {
        SET(i->dst, initial >> shift);

        uint8_t last_shifted_out = shift > i->size ? 0 : BIT(initial, shift - 1);
        CARRY_SET(i->context, last_shifted_out);
        EXTENDED_SET(i->context, last_shifted_out);
    }

    uint32_t result = GET(i->dst);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);

    return 2 * shift;
}

Instruction* gen_asd(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "ASL" : "ASR", direction ? lsl : asr); // ASL = LSL
}

Instruction* gen_asd_mem(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_memory_instruction(opcode, m, direction ? "ASL" : "ASR", direction ? lsl : asr); // ASL = LSL
}

Instruction* gen_lsd(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "LSL" : "LSR", direction ? lsl : lsr);
}

Instruction* gen_lsd_mem(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_memory_instruction(opcode, m, direction ? "LSL" : "LSR", direction ? lsl : lsr);
}

int rol(Instruction* i)
{
    uint32_t initial = FETCH_EA_AND_GET(i->dst);

    int rotation = FETCH_EA_AND_GET(i->src) % i->size;
    if (rotation == 0)
        rotation = 8;

    if (rotation > 0) // TODO always true!
    {
        SET(i->dst, initial << rotation | FRAGMENT(initial, i->size - 1, i->size - rotation));

        CARRY_SET(i->context, BIT(initial, i->size - rotation));
    }
    else
        CARRY_SET(i->context, 0);

    uint32_t result = GET(i->dst);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);

    return 2 * rotation;
}

int ror(Instruction* i)
{
    uint32_t initial = FETCH_EA_AND_GET(i->dst);

    int rotation = FETCH_EA_AND_GET(i->src) % i->size;
    if (rotation == 0)
        rotation = 8;

    if (rotation > 0) //TODO always true!
    {
        SET(i->dst, initial >> rotation | FRAGMENT(initial, rotation - 1, 0) << (i->size - rotation));

        CARRY_SET(i->context, BIT(initial, rotation - 1));
    }
    else
        CARRY_SET(i->context, 0);

    uint32_t result = GET(i->dst);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);

    return 2 * rotation;
}

Instruction* gen_rod(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "ROL" : "ROR", direction ? rol : ror);
}

Instruction* gen_rod_mem(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_memory_instruction(opcode, m, direction ? "ROL" : "ROR", direction ? rol : ror);
}

int roxl(Instruction* i)
{
    uint32_t initial = FETCH_EA_AND_GET(i->dst);

    int rotation = GET(i->src) % i->size;
    if (rotation == 0)
        rotation = 8;

    if (rotation > 0) // TODO always true
    {
        uint32_t rotated = rotation > 1 ? FRAGMENT(initial, i->size - 1, i->size - rotation + 1) : 0;
        SET(i->dst, initial << rotation | EXTENDED(i->context) << (rotation - 1) | rotated);

        uint8_t last_shifted_out = BIT(initial, i->size - rotation);
        CARRY_SET(i->context, last_shifted_out);
        EXTENDED_SET(i->context, last_shifted_out);
    }
    else
        CARRY_SET(i->context, EXTENDED(i->context));

    uint32_t result = GET(i->dst);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);

    return 2 * rotation;
}

int roxr(Instruction* i)
{
    FETCH_EA(i->dst);
    uint32_t initial = GET(i->dst);

    int rotation = GET(i->src) % i->size;
    if (rotation > 0)
    {
        SET(i->dst, initial >> rotation | FRAGMENT(initial, rotation - 1, 0) << (i->size - rotation + 1) | EXTENDED(i->context) << (i->size - rotation));

        uint8_t last_shifted_out = BIT(initial, rotation - 1);
        CARRY_SET(i->context, last_shifted_out);
        EXTENDED_SET(i->context, last_shifted_out);
    }

    uint32_t result = GET(i->dst);
    OVERFLOW_SET(i->context, false);
    ZERO_SET(i->context, result == 0);
    NEGATIVE_SET(i->context, BIT(result, i->size - 1) == 1);

    return 2 * rotation;
}

Instruction* gen_roxd(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_instruction(opcode, m, direction ? "ROXL" : "ROXR", direction ? roxl : roxr);
}

Instruction* gen_roxd_mem(uint16_t opcode, M68k* m)
{
    bool direction = BIT(opcode, 8);
    return gen_shift_memory_instruction(opcode, m, direction ? "ROXL" : "ROXR", direction ? roxl : roxr);
}

int swap(Instruction* i)
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

    return 0;
}

Instruction* gen_swap(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "SWAP", swap);
    i->size = Long;
    i->src = operand_make_data_register(FRAGMENT(opcode, 5, 0), i);
    i->base_cycles = 4;
    return i;
}
