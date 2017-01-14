#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instruction.h"
#include "m68k.h"
#include "operands.h"

M68k* m68k_make()
{
    M68k* m68k = calloc(1, sizeof(M68k));

    m68k->opcode_table = calloc(0x10000, sizeof(Instruction*));

    // Generate every possible opcode
    for (int opcode = 0; opcode < 0x10000; ++opcode)
    {
        // Manual breakpoint!
        if (opcode == 0x7217)
        {
            printf("don't get optimized away please");
        }

        Instruction* instr = instruction_generate(m68k, opcode);

        if (!instruction_valid(instr))
        {
            instruction_free(instr);
            continue;
        }

        m68k->opcode_table[opcode] = instr;

        /*printf("opcode %#04X: %s", opcode, instr->name);
        for (int i = 0; i < instr->operand_count; ++i)
            printf(" %s", operand_tostring(instr->operands[i]));
        printf("\n");*/
    }

    return m68k;
}

void m68k_free(M68k* m)
{
    for (int opcode = 0; opcode < 0x10000; ++opcode)
        instruction_free(m->opcode_table[opcode]);

    free(m->opcode_table);
    free(m);
}

DecodedInstruction* m68k_decode(M68k* m, uint32_t instr_address)
{
    uint16_t opcode = m68k_read_w(m, instr_address);
    printf("Decoding opcode %#06X [%#010X]...\n", opcode, instr_address);

    Instruction* instr = m->opcode_table[opcode];
    if (instr == NULL)
    {
        printf("Opcode %#06X cannot be found in the opcode table\n", opcode);
        return NULL;
    }

    DecodedInstruction* decoded = calloc(1, sizeof(DecodedInstruction));

    char* buffer = calloc(50, sizeof(char));
    int pos = sprintf(buffer, "%s", instr->name);

    char* size_symbol;
    switch (instr->size)
    {
    case Byte:
        size_symbol = ".b";
        break;
    case Word:
        size_symbol = ".w";
        break;
    case Long:
        size_symbol = ".l";
        break;
    default:
        size_symbol = " ";
    }
    pos += sprintf(buffer + pos, "%s ", size_symbol);

    if (instr->src != NULL)
        pos += operand_tostring(instr->src, instr_address, buffer + pos);

    if (instr->src != NULL && instr->dst != NULL)
        pos += sprintf(buffer + pos, ",");

    if (instr->dst != NULL)
        pos += operand_tostring(instr->dst, instr_address, buffer + pos);

    buffer[pos] = '\0';

    printf("Decoded \"%s\"\n", buffer);
    decoded->mnemonics = buffer;
    return decoded;
}

uint32_t m68k_step(M68k* m)
{
    uint16_t opcode = m68k_read_w(m, m->pc);
    return m68k_execute(m, opcode);
}

// TODO make private
uint32_t m68k_execute(M68k* m, uint16_t opcode)
{
    // Fetch the instruction
    Instruction* instr = m->opcode_table[opcode];

    // Manual breakpoint!
    if (m->pc == 0x23C)
    {
        printf("don't get optimized away please");
    }

    if (instr == NULL)
    {
        printf("Opcode %#06X cannot be found in the opcode table\n", opcode);
    }
    else
    {
        DecodedInstruction* d = m68k_decode(m, m->pc);
        // TODO different func to generate and print decoded instr

        instr->func(instr);

        m->pc += instr->length;
        // TODO can only address 2^24 bytes in practice

        free(d);
    }

    return m->pc;
}

void m68k_push(int value)
{
    // TODO
}

int m68k_pop()
{
    return 0; // TODO
}

void m68k_jump(int address)
{
    // TODO necesary?
}
