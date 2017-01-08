#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instruction.h"
#include "m68k.h"
#include "operands.h"

M68k* m68k_make(uint8_t* memory)
{
    M68k* m68k = calloc(1, sizeof(M68k));
    m68k->memory = memory;

    m68k->opcode_table = calloc(0x10000, sizeof(Instruction*));

    // Generate every possible opcode
    for (int opcode = 0; opcode < 0x10000; ++opcode)
    {
        if (opcode == 0x0200)
        {
            printf("");
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

DecodedInstruction* m68k_decode(M68k* m, uint32_t pc)
{
    uint16_t opcode = m68k_read_w(m, pc);
    printf("Decoding opcode %#06X [%#010X]...\n", opcode, pc);

    Instruction* instr = m->opcode_table[opcode];
    if (instr == NULL)
    {
        printf("Opcode %#06X cannot be found in the opcode table\n", opcode);
        return NULL;
    }

    DecodedInstruction* decoded = calloc(1, sizeof(DecodedInstruction));

    char* buffer = calloc(50, sizeof(char));
    int pos = sprintf(buffer, "%s ", instr->name);

    if (instr->src != NULL)
        pos += operand_tostring(instr->src, buffer + pos);
    if (instr->dst != NULL)
        pos += operand_tostring(instr->dst, buffer + pos);

    buffer[pos] = '\0';

    printf("Decoded \"%s\"\n", buffer);
    decoded->mnemonics = buffer;
    return decoded;
}

uint32_t m68k_step(M68k* m)
{
    uint16_t opcode = (m->memory[m->pc] << 8) | m->memory[m->pc + 1];
    return m68k_execute(m, opcode);
}

// TODO make private
uint32_t m68k_execute(M68k* m, uint16_t opcode)
{
    // Fetch the instruction
    Instruction* instr = m->opcode_table[opcode];

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

uint8_t m68k_read_b(M68k* m, uint32_t address)
{
    return m->memory[address];
}

uint16_t m68k_read_w(M68k* m, uint32_t address)
{
    return
        (m->memory[address] << 8) |
        m->memory[address + 1];
}

uint32_t m68k_read_l(M68k* m, uint32_t address)
{
    return
        (m->memory[address] << 24) |
        (m->memory[address + 1] << 16) |
        (m->memory[address + 2] << 8) |
        m->memory[address + 3];
}

uint32_t m68k_read(M68k* m, Size size, uint32_t address)
{
    switch (size)
    {
    case Byte:
        return m68k_read_b(m, address);
    case Word:
        return m68k_read_w(m, address);
    case Long:
        return m68k_read_l(m, address);
    default:
        return 0xFF; // TODO error?
    }
}

void m68k_write_b(M68k* m, uint32_t address, uint8_t value)
{
    m->memory[address] = value;
}

void m68k_write_w(M68k* m, uint32_t address, uint16_t value)
{
    m->memory[address] = (value & 0xFF00) >> 8;
    m->memory[address + 1] = value & 0xFF;
}

void m68k_write_l(M68k* m, uint32_t address, uint32_t value)
{
    m->memory[address] = (value & 0xFF000000) >> 24;
    m->memory[address + 1] = (value & 0xFF0000) >> 16;
    m->memory[address + 2] = (value & 0xFF00) >> 8;
    m->memory[address + 3] = value & 0xFF;
}

void m68k_write(M68k* m, Size size, uint32_t address, uint32_t value)
{
    switch (size)
    {
    case Byte:
        m68k_write_b(m, address, value);
    case Word:
        m68k_write_w(m, address, value);
    case Long:
        m68k_write_l(m, address, value);
    }
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
