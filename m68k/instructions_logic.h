#pragma once

#include "globals.h"
#include "instructions_logic.h"
#include "m68k.h"
#include "operands.h"

#define GET(operand) (operand.get(operand))
#define SET(operand, value) (operand.set(operand, value))

#define Z(x) _m68k.flags = _m68k.flags & (0xFFFF ^ 1 << 2)
#define V(x) _m68k.flags = _m68k.flags & (0xFFFF ^ 1 << 1)
#define C(x) _m68k.flags = _m68k.flags & (0xFFFF ^ 1)

#define DEFINE_INSTR(NAME) void NAME(Operand *operands); Instruction gen_ ## NAME (uint16_t opcode);

DEFINE_INSTR(and)
