#include <stdbool.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instruction.h"
#include "m68k.h"
#include "operands.h"

Instruction* gen_bit_instruction(uint16_t opcode, M68k* m, char* name, InstructionFunc func)
{
    Instruction* i = instruction_make(m, name, func);
    i->src = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);
    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i);

    // The operation size varies between data registers and memory locations
    // http://oldwww.nvg.ntnu.no/amiga/MC680x0_Sections/btst.HTML
    if (i->dst != NULL) // TODO temp check (remove when all addr modes are in)
        i->size = i->dst->type == DataRegister ? Long : Byte;

    return i;
}

int bchg(Instruction* i)
{
    uint8_t bit = GET(i->src) % i->size; // TODO

    FETCH_EA(i->dst);
    uint32_t initial = GET(i->dst);
    SET(i->dst, BIT_CHG(initial, bit, !BIT(initial, bit)));

    ZERO_SET(i->context, BIT(initial, bit) == 0);

    return 0;
}

Instruction* gen_bchg(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction(opcode, m, "BCHG", bchg);
}

int bclr(Instruction* i)
{
    uint8_t bit = GET(i->src) % i->size;

    FETCH_EA(i->dst);
    int initial = GET(i->dst);
    SET(i->dst, BIT_CLR(initial, bit));

    ZERO_SET(i->context, BIT(initial, bit) == 0);

    return 0;
}

Instruction* gen_bclr(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction(opcode, m, "BCLR", bclr);
}

int bset(Instruction* i)
{
    uint8_t bit = GET(i->src) % i->size;

    FETCH_EA(i->dst);
    uint32_t initial = GET(i->dst);
    SET(i->dst, BIT_SET(initial, bit));

    ZERO_SET(i->context, BIT(initial, bit) == 0);

    return 0;
}

Instruction* gen_bset(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction(opcode, m, "BSET", bset);
}

int btst(Instruction* i)
{
    int bit = GET(i->src) % i->size;

    FETCH_EA(i->dst);
    int set = BIT(GET(i->dst), bit);

    ZERO_SET(i->context, !set);

    return 0;
}

Instruction* gen_btst(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction(opcode, m, "BTST", btst);
}

int btst_imm(Instruction* i)
{
    int bit = m68k_fetch(i->context) % i->size;
    int set = BIT(FETCH_EA_AND_GET(i->dst), bit);

    ZERO_SET(i->context, !set);

    return 0;
}

Instruction* gen_btst_imm(uint16_t opcode, M68k* m)
{
    Instruction* i = instruction_make(m, "BTST", btst_imm);
    i->base_length = 4;
    i->size = Long;
    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i); // TODO use operand for immediate data so that it gets properly disassembled and the same implem can be used
    return i;
}