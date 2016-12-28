#pragma once

#include <stdint.h>

#include "bit_utils.h"

#define CARRY_BIT 0
#define OVERFLOW_BIT 1
#define ZERO_BIT 2
#define NEGATIVE_BIT 3
#define EXTENDED_BIT 4

#define CARRY(context) BIT(context->status, CARRY_BIT)
#define OVERFLOW(context) BIT(context->status, OVERFLOW_BIT)
#define ZERO(context) BIT(context->status, ZERO_BIT)
#define NEGATIVE(context) BIT(context->status, NEGATIVE_BIT)
#define EXTENDED(context) BIT(context->status, EXTENDED_BIT)

#define CARRY_SET(context, b) context->status = BIT_CHG(context->status, CARRY_BIT, b)
#define OVERFLOW_SET(context, b) context->status = BIT_CHG(context->status, OVERFLOW_BIT, b)
#define ZERO_SET(context, b) context->status = BIT_CHG(context->status, ZERO_BIT, b)
#define NEGATIVE_SET(context, b) context->status = BIT_CHG(context->status, NEGATIVE_BIT, b)
#define EXTENDED_SET(context, b) context->status = BIT_CHG(context->status, EXTENDED_BIT, b)

struct Instruction;
struct DecodedInstruction;

typedef struct M68k {
    int32_t data_registers[8];
    uint32_t address_registers[8];
    uint16_t status;
    uint32_t pc;

    struct Instruction** opcode_table;
    
    uint8_t* memory;
} M68k;

typedef struct Instruction* (GenFunc)(uint16_t opcode, M68k* context);

typedef struct {
    uint16_t pattern;
    uint16_t mask;
    GenFunc* generator;
} Pattern;

M68k* m68k_make(uint8_t* memory);
void m68k_free(M68k*);

struct DecodedInstruction* m68k_decode(M68k*, uint32_t pc);

// Execute one instruction and return the current program counter value
uint32_t m68k_step(M68k*);

// Execute the given opcode and return the current program counter value
uint32_t m68k_execute(M68k*, uint16_t opcode);

void m68k_push(int value); // TODO type?
int m68k_pop();
void m68k_jump(int address);
