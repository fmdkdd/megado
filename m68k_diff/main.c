#include <stdint.h>
#include <stdio.h>

#include "musashi/m68k.h"
#include "m68k/m68k.h" // Names might clash...

// TODO add https://github.com/notaz/cyclone68000 to the list?

#define READ_BYTE_IMPL(name, memory, address_type, value_type)\
    value_type name ## (address_type address) {\
        return memory ## [address];\
    }

#define READ_WORD_IMPL(name, memory, address_type, value_type)\
    value_type name ## (address_type address) {\
        return memory ## [address] << 8 | memory ## [address + 1];\
    }

#define READ_LONG_IMPL(name, memory, address_type, value_type)\
    value_type name ## (address_type address) {\
        return memory ## [address] << 24 | memory ## [address + 1] << 16 | memory ## [address + 2] << 8 | memory ## [address + 3];\
    }

#define WRITE_BYTE_IMPL(name, memory, address_type, value_type)\
    void name ## (address_type address, value_type value) {\
        memory ## [address] = value & 0xFF;\
    }

#define WRITE_WORD_IMPL(name, memory, address_type, value_type)\
    void name ## (address_type address, value_type value) {\
        memory ## [address] = (value & 0xFF00) >> 8;\
        memory ## [address + 1] = value & 0x00FF;\
    }

#define WRITE_LONG_IMPL(name, memory, address_type, value_type)\
    void name ## (address_type address, value_type value) {\
        memory ## [address] = (value & 0xFF000000) >> 24;\
        memory ## [address + 1] = (value & 0x00FF0000) << 16;\
        memory ## [address + 2] = (value & 0x0000FF00) >> 8;\
        memory ## [address + 3] = value & 0x000000FF;\
    }

// Musashi I/O

uint8_t* memory_musashi;

unsigned int m68k_read_memory_8(unsigned int address)
{
    return memory_musashi[address];
}

unsigned int m68k_read_memory_16(unsigned int address)
{
    return memory_musashi[address] << 8 | memory_musashi[address + 1];
}

unsigned int m68k_read_memory_32(unsigned int address)
{
    return memory_musashi[address] << 24 | memory_musashi[address + 1] << 16 | memory_musashi[address + 2] << 8 | memory_musashi[address + 3];
}

void m68k_write_memory_8(unsigned int address, unsigned int value)
{
    memory_musashi[address] = value & 0xFF;
}

void m68k_write_memory_16(unsigned int address, unsigned int value)
{
    memory_musashi[address] = (value & 0xFF00) >> 8;
    memory_musashi[address + 1] = value & 0x00FF;
}

void m68k_write_memory_32(unsigned int address, unsigned int value)
{
    memory_musashi[address] = (value & 0xFF000000) >> 24;
    memory_musashi[address + 1] = (value & 0x00FF0000) << 16;
    memory_musashi[address + 2] = (value & 0x0000FF00) >> 8;
    memory_musashi[address + 3] = value & 0x000000FF;
}

READ_WORD_IMPL(m68k_read_disassembler_16, memory_musashi, unsigned int, unsigned int)
READ_LONG_IMPL(m68k_read_disassembler_32, memory_musashi, unsigned int, unsigned int)

// xxx emulator I/O

uint8_t* memory_xxx;

uint8_t m68k_read_b(M68k* m, uint32_t address)
{
    return memory_xxx[address];
}

uint16_t m68k_read_w(M68k* m, uint32_t address)
{
    return memory_xxx[address] << 8 | memory_xxx[address + 1];
}

uint32_t m68k_read_l(M68k* m, uint32_t address)
{
    return memory_xxx[address] << 24 | memory_xxx[address + 1] << 16 | memory_xxx[address + 2] << 8 | memory_xxx[address + 3];
}

void m68k_write_b(M68k* m, uint32_t address, uint8_t value)
{
    memory_xxx[address] = value & 0xFF;
}

void m68k_write_w(M68k* m, uint32_t address, uint16_t value)
{
    memory_xxx[address] = (value & 0xFF00) >> 8;
    memory_xxx[address + 1] = value & 0x00FF;
}

void m68k_write_l(M68k* m, uint32_t address, uint32_t value)
{
    memory_xxx[address] = (value & 0xFF000000) >> 24;
    memory_xxx[address + 1] = (value & 0x00FF0000) << 16;
    memory_xxx[address + 2] = (value & 0x0000FF00) >> 8;
    memory_xxx[address + 3] = value & 0x000000FF;
}

// Data dump functions

char* dump_format = "PC %04x, SR %04x, A0 %04x, A1 %04x, A2 %04x, A3 %04x, A4 %04x, A5 %04x, A6 %04x, A7 %04x, A0 %04x, A1 %04x, A2 %04x, A3 %04x, A4 %04x, A5 %04x, A6 %04x, A7 %04x\n";

#define MUSASHI_REG(reg) m68k_get_reg(NULL, M68K_REG_ ## reg)

void musashi_dump(FILE* file)
{
    fprintf(file, dump_format,
        MUSASHI_REG(PC), MUSASHI_REG(SR),
        MUSASHI_REG(A0), MUSASHI_REG(A1), MUSASHI_REG(A2), MUSASHI_REG(A3), MUSASHI_REG(A4), MUSASHI_REG(A5), MUSASHI_REG(A6), MUSASHI_REG(A7),
        MUSASHI_REG(D0), MUSASHI_REG(D1), MUSASHI_REG(D2), MUSASHI_REG(D3), MUSASHI_REG(D4), MUSASHI_REG(D5), MUSASHI_REG(D6), MUSASHI_REG(D7));
}

#define XXX_ADDR_REG(reg) xxx->address_registers[reg]
#define XXX_DATA_REG(reg) xxx->data_registers[reg]

M68k* xxx = NULL;

void xxx_dump(FILE* file)
{
    fprintf(file, dump_format,
        xxx->pc, xxx->status,
        XXX_ADDR_REG(0), XXX_ADDR_REG(1), XXX_ADDR_REG(2), XXX_ADDR_REG(3), XXX_ADDR_REG(4), XXX_ADDR_REG(5), XXX_ADDR_REG(6), XXX_ADDR_REG(7),
        XXX_DATA_REG(0), XXX_DATA_REG(1), XXX_DATA_REG(2), XXX_DATA_REG(3), XXX_DATA_REG(4), XXX_DATA_REG(5), XXX_DATA_REG(6), XXX_DATA_REG(7));
}

void musashi_instr_callback()
{
    /* The following code would print out instructions as they are executed */

    static char buff[100];
    static char buff2[100];
    static unsigned int pc;
    static unsigned int instr_size;
    pc = m68k_get_reg(NULL, M68K_REG_PC);
    instr_size = m68k_disassemble(buff, pc, M68K_CPU_TYPE_68000);
    //make_hex(buff2, pc, instr_size);
    printf("E %03x: %s\n", pc, buff);
}

#define MAX_ROM_SIZE 0x10000
#define MAX_MEM_SIZE 0x1000000

int main(int argc, char* argv[])
{
    // Arg 1: rom path
    // Arg 2: start offset (hex)

    memory_musashi = calloc(MAX_MEM_SIZE, sizeof(uint8_t));
    memory_xxx = calloc(MAX_MEM_SIZE, sizeof(uint8_t));

    // Load the rom file

    uint8_t rom[MAX_ROM_SIZE];

    FILE* rom_file = fopen(argv[1], "rb");
    if (rom_file == NULL)
    {
        printf("Cannot open file \"%d\"", argv[1]);
        return 1;
    }

    fread(memory_musashi, MAX_ROM_SIZE, sizeof(uint8_t), rom_file);
    rewind(rom_file);
    fread(memory_xxx, MAX_ROM_SIZE, sizeof(uint8_t), rom_file);
    fclose(rom_file);

    // Setup Musashi
    m68k_init();
    m68k_set_cpu_type(M68K_CPU_TYPE_68000);
    m68k_set_instr_hook_callback(musashi_instr_callback);
    m68k_pulse_reset();

    // Setup xxx
    xxx = m68k_make();

    // Start the program at an optional offset
    if (argc > 2)
    {
        int offset = strtol(argv[2], NULL, 16);

        m68k_set_reg(M68K_REG_PC, offset);
        xxx->pc = offset;
    }

    FILE* dumpfile_musashi = fopen("musashi_dump.txt", "w");
    FILE* dumpfile_xxx = fopen("xxx_dump.txt", "w");

    musashi_dump(dumpfile_musashi);
    xxx_dump(dumpfile_xxx);

    for (int i = 0; i < 10; ++i)
    {
        // Musashi
        m68k_execute(0);
        musashi_dump(dumpfile_musashi);

        // xxx
        m68k_step(xxx);
        xxx_dump(dumpfile_xxx);
    }

    free(memory_musashi);
    free(memory_xxx);

    m68k_free(xxx);

    fclose(dumpfile_musashi);
    fclose(dumpfile_xxx);

    return 0;
}
