#include <m68k/m68k.h>
#include <m68k/instruction.h>
#include <stdio.h>
#include <stdlib.h>

#include "genesis.h"

Genesis* genesis_make()
{
    Genesis* g = calloc(1, sizeof(Genesis));
    g->memory = calloc(0x1000000, sizeof(uint8_t));
    g->m68k = m68k_make(g->memory);
    return g;
}

void genesis_free(Genesis* g)
{
    m68k_free(g->m68k);
    free(g->memory);
    free(g);
}

void genesis_load_rom_file(Genesis* g, char* path)
{
    FILE* file = fopen(path, "rb");
    if (!file)
    {
        printf("Cannot read file \"%s\"", path);
        return;
    }

    fseek(file, 0, SEEK_END);
    int file_length = ftell(file);
    fseek(file, 0, SEEK_SET);

    fread(g->memory, sizeof(uint32_t), 0x1000000, file);

    fclose(file);
}

void genesis_load_rom_data(Genesis* g, uint8_t* data)
{
    // TODO
}

struct DecodedInstruction* genesis_decode(Genesis* g, uint32_t pc)
{
    printf(".%p %p.\n", g, g->m68k);
    return m68k_decode(g->m68k, pc);
}

#define WORD(x) ((x)[0] << 8 | (x)[1])
#define LONG(x) ((x)[0] << 24 | (x)[1] << 16 | (x)[2] << 8 | (x)[3])

void genesis_setup(Genesis* g)
{
    // http://darkdust.net/writings/megadrive/initializing
    // http://md.squee.co/Howto:Initialise_a_Mega_Drive

    // TODO sp

    g->m68k->pc = LONG(g->memory + 4); // Entry point
    printf("Entry point @%#010X\n", g->m68k->pc);

    // TODO interrupts

}

uint32_t genesis_step(Genesis* g)
{
    return m68k_step(g->m68k);
}

uint8_t* genesis_memory(Genesis* g) { return g->memory; }
M68k* genesis_m68k(Genesis* g) { return g->m68k; }