#include <stdio.h>
#include <stdlib.h>

#include "m68k.h"
#include "../genesis.h"
#include "../joypad.h"
#include "../vdp.h"

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
    case InvalidSize:
    default:
        fprintf(stderr, "Invalid size %x in m68k_read\n", size);
        exit(1);
    }
}

uint8_t m68k_read_b(M68k* m, uint32_t address)
{
    address &= 0xFFFFFF; // 24-bit address bus

    // Z80 address space
    if (address >= 0xA00000 && address < 0xA10000) {
      return z80_read(m->genesis->z80, address & 0xFFFF);
    }

    switch (address)
    {

        // https://wiki.megadrive.org/index.php?title=IO_Registers

    case 0xA10000: // Version port
    case 0xA10001:
        return
            (m->genesis->region != Region_Japan) << 7 | // Domestic (0) / Export (1)
            (m->genesis->region == Region_Europe) << 6 | // NTSC (0) / PAL (1)
            false << 5 | // Sega CD connected
            false; // Version

    case 0xA10002:
    case 0xA10003:
        return joypad_read(m->genesis->joypad);
        break;

    case 0xA11100:
      // The 68000 has the bus if the Z80 is not running (0: has the bus)
      return z80_bus_ack(m->genesis->z80);

    case 0xA11200:
      return 0;

    case 0xC00000: // VDP data port
    case 0xC00002:
        return BYTE_HI(vdp_read_data(m->genesis->vdp)); // TODO add direct read 16b read in m68k_read_w
    case 0xC00001:
    case 0xC00003:
        return BYTE_LO(vdp_read_data(m->genesis->vdp));

    case 0xC00004: // VDP control port
    case 0xC00006:
        return BYTE_HI(vdp_read_control(m->genesis->vdp));
    case 0xC00005:
    case 0xC00007:
        return BYTE_LO(vdp_read_control(m->genesis->vdp));

    case 0xC00008:
        return BYTE_HI(vdp_get_hv_counter(m->genesis->vdp));
    case 0xC00009:
        return BYTE_LO(vdp_get_hv_counter(m->genesis->vdp));

    default:
        return m->genesis->memory[address];
    }
}

uint16_t m68k_read_w(M68k* m, uint32_t address)
{
    return
        m68k_read_b(m, address) << 8 |
        m68k_read_b(m, address + 1);
}

uint32_t m68k_read_l(M68k* m, uint32_t address)
{
    return
        ((uint32_t) m68k_read_w(m, address)) << 16 |
        m68k_read_w(m, address + 2);
}

void m68k_write(M68k* m, Size size, uint32_t address, uint32_t value)
{
    switch (size)
    {
    case Byte:
        m68k_write_b(m, address, value);
        break;
    case Word:
        m68k_write_w(m, address, value);
        break;
    case Long:
        m68k_write_l(m, address, value);
        break;
    case InvalidSize:
    default:
        fprintf(stderr, "Invalid size %x in m68k_write\n", size);
        exit(1);
    }
}

void m68k_write_b(M68k* m, uint32_t address, uint8_t value)
{
    address &= 0xFFFFFF; // 24-bit address bus

    // Cannot write to ROM
    if (address <= 0x3FFFFF)
        return;

    // Z80 address space
    if (address >= 0xA00000 && address < 0xA10000) {
      z80_write(m->genesis->z80, address & 0xFFFF, value);
    }

    else if (address == 0xA10002 || address == 0xA10003) {
        joypad_write(m->genesis->joypad, value);
    }

    // BUSREQ
    else if (address == 0xA11100) {
      z80_bus_req(m->genesis->z80, value);
    }

    // RESET
    else if (address == 0xA11200) {
      z80_reset(m->genesis->z80, value);
    }

    // " Writing to the VDP control or data ports is interpreted as a 16-bit
    //   write, with the LSB duplicated in the MSB"
    // http://www.tmeeco.eu/BitShit/CMDHW.TXT
    else if (address == 0xC00000)
    {
        vdp_write_data(m->genesis->vdp, value & (value << 8));
    }
    else if (address == 0xC00004)
    {
        vdp_write_control(m->genesis->vdp, value & (value << 8));
    }

    else if (address > 0x82e0 && address < 0x82ff)
        printf("");

    m->genesis->memory[address & 0xFFFFFF] = value;
}

void m68k_write_w(M68k* m, uint32_t address, uint16_t value)
{
    address &= 0xFFFFFF;

    switch (address)
    {
    case 0xA11100:
      z80_bus_req(m->genesis->z80, value >> 8);
      break;

    case 0xA11200:
      z80_reset(m->genesis->z80, value >> 8);
      break;

    case 0xC00000: // VDP data port
    case 0xC00002:
        vdp_write_data(m->genesis->vdp, value);
        break;

    case 0xC00004: // VDP control port
    case 0xC00006:
        vdp_write_control(m->genesis->vdp, value);
        break;

    default:
        m68k_write_b(m, address, (value & 0xFF00) >> 8);
        m68k_write_b(m, address + 1, value & 0xFF);
    }
}

void m68k_write_l(M68k* m, uint32_t address, uint32_t value)
{
    m68k_write_w(m, address, (value & 0xFFFF0000) >> 16);
    m68k_write_w(m, address + 2, value & 0xFFFF);
}
