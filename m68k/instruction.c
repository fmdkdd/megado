#include <stdlib.h>

#include "instruction.h"
#include "instructions_arithmetic.h"
#include "instructions_bit.h"
#include "instructions_control.h"
#include "instructions_logic.h"
#include "instructions_shift.h"
#include "instructions_transfer.h"
#include "m68k.h"
#include "operands.h"

Instruction* instruction_make(M68k* context, char* name, InstructionFunc func)
{
    Instruction* i = calloc(1, sizeof(Instruction));
    i->context = context;
    i->name = name;
    i->func = func;
    return i;
}

void instruction_free(Instruction* instr)
{
    if (instr == NULL)
        return;

    free(instr->src);
    free(instr->dst);
    free(instr);
}

static Pattern _patterns[] =
{
    { 0x0100, 0x37C0, &gen_btst }, // TODO other btst form
    { 0x0140, 0x37C0, &gen_bchg }, // TODO other bchg form
    { 0x0180, 0x37C0, &gen_bclr }, // TODO other bclr form
    { 0x01C0, 0x37C0, &gen_bset }, // TODO other bset form
    { 0x41C0, 0xF1C0, &gen_lea },
    { 0x4200, 0xFF00, &gen_clr },
    { 0x4600, 0xFF00, &gen_not },
    { 0x4840, 0xFFF8, &gen_swap },
    { 0x4840, 0xFFC0, &gen_pea },
    { 0x4A00, 0xFF00, &gen_tst },
    { 0x4E75, 0xFFFF, &gen_rts },
    { 0x4E80, 0xFFC0, &gen_jsr },
    { 0x4EC0, 0xFFC0, &gen_jmp },
    //{ 0x5000, 0xF000, &gen_scc },
    { 0x6000, 0xFF00, &gen_bra },
    { 0x6100, 0xFF00, &gen_bsr },
    { 0x6000, 0xF000, &gen_bcc },
    { 0x8000, 0xF000, &gen_or },
    { 0xB000, 0xF000, &gen_eor },
    { 0xC000, 0xF000, &gen_and },
    //{0xC100, 0xF130, &gen_exg }, TODO conflict with ADD, how to disambiguate?
    { 0xC0C0, 0xF1C0, &gen_mulu },
    { 0xC1C0, 0xF1C0, &gen_muls },
    { 0xE2C0, 0xFEC0, &gen_lsX },
};

int pattern_match(uint16_t opcode, Pattern pattern)
{
    return (opcode & pattern.mask) == pattern.pattern;
}

Instruction* pattern_generate(Pattern pattern, uint16_t opcode, M68k* context)
{
    return pattern.generator(opcode, context);
}

int operand_length(Operand* operand)
{
    if (operand == NULL)
        return 0;

    switch (operand->type)
    {
    case AbsoluteShort:
    case ProgramCounterOffset:
        return 2;
    case AbsoluteLong:
        return 4;
    default:
        return 0;
    }
}

Instruction* instruction_generate(M68k* context, uint16_t opcode)
{
    int pattern_count = sizeof(_patterns) / sizeof(Pattern);

    for (int i = 0; i < pattern_count; ++i)
        if (pattern_match(opcode, _patterns[i]))
        {
            // Generate the instruction
            Instruction* instr = pattern_generate(_patterns[i], opcode, context);

            if (instr == NULL)
                return NULL;

            // Compute its length in bytes
            instr->length = 2 + operand_length(instr->src) + operand_length(instr->dst);

            return instr;
        }

    return NULL;
}

bool instruction_valid(Instruction* instr)
{
    // Check that the generated instruction is valid
    if (instr == NULL)
        return false;

    return true;
}
