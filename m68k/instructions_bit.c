#include <stdbool.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instruction.h"
#include "m68k.h"
#include "operands.h"

Instruction* gen_bit_instruction(uint16_t opcode, M68k* m, char* name, InstructionFunc func)
{
    Instruction* i = instruction_make(m, name, func);

    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i);

    // The operation size varies between data registers and memory locations
    // http://oldwww.nvg.ntnu.no/amiga/MC680x0_Sections/btst.HTML
    if (i->dst != NULL)
        i->size = i->dst->type == DataRegister ? Long : Byte;

    i->src = operand_make_data_register(FRAGMENT(opcode, 11, 9), i);

    return i;
}

Instruction* gen_bit_instruction_immediate(uint16_t opcode, M68k* m, char* name, InstructionFunc func)
{
    Instruction* i = instruction_make(m, name, func);
    i->base_length = 4; // TODO still necessary?

    i->dst = operand_make(FRAGMENT(opcode, 5, 0), i);
    
    if (i->dst != NULL)
        i->size = i->dst->type == DataRegister ? Long : Byte;

    i->src = operand_make_immediate_value(i->size, i);

    return i;
}

int bchg(Instruction* i)
{
    uint8_t bit = FETCH_EA_AND_GET(i->src) % i->size;

    uint32_t initial = FETCH_EA_AND_GET(i->dst);
    SET(i->dst, BIT_CHG(initial, bit, !BIT(initial, bit)));

    ZERO_SET(i->context, BIT(initial, bit) == 0);

    return 0;
}

Instruction* gen_bchg(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction(opcode, m, "BCHG", bchg);
}

Instruction* gen_bchg_imm(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction_immediate(opcode, m, "BCHG", bchg);
}

int bclr(Instruction* i)
{
    uint8_t bit = FETCH_EA_AND_GET(i->src) % i->size;

    int initial = FETCH_EA_AND_GET(i->dst);
    SET(i->dst, BIT_CLR(initial, bit));

    ZERO_SET(i->context, BIT(initial, bit) == 0);

    return 0;
}

Instruction* gen_bclr(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction(opcode, m, "BCLR", bclr);
}

Instruction* gen_bclr_imm(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction_immediate(opcode, m, "BCLR", bclr);
}

int bset(Instruction* i)
{
    uint8_t bit = FETCH_EA_AND_GET(i->src) % i->size;

    uint32_t initial = FETCH_EA_AND_GET(i->dst);
    SET(i->dst, BIT_SET(initial, bit));

    ZERO_SET(i->context, BIT(initial, bit) == 0);

    return 0;
}

Instruction* gen_bset(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction(opcode, m, "BSET", bset);
}

Instruction* gen_bset_imm(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction_immediate(opcode, m, "BSET", bset);
}

int btst(Instruction* i) // TODO check doc
{
    int bit = FETCH_EA_AND_GET(i->src) % i->size;
    int set = BIT(FETCH_EA_AND_GET(i->dst), bit);

    ZERO_SET(i->context, !set);

    return 0;
}

Instruction* gen_btst(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction(opcode, m, "BTST", btst);
}

Instruction* gen_btst_imm(uint16_t opcode, M68k* m)
{
    return gen_bit_instruction_immediate(opcode, m, "BTST", btst);
}
