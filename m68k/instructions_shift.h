#pragma once

#include "instruction.h"
#include "m68k.h"
#include "operands.h"

#define DEFINE_INSTR(NAME) Instruction* gen_ ## NAME (uint16_t opcode, M68k* context)

DEFINE_INSTR(lsX);
DEFINE_INSTR(swap);
