#pragma once

#include <stdint.h>

#include "bit_utils.h"

struct Operand;
struct Instruction;

/*
 * Macros to read/write operand data
 */

// Fetch and store the operand's effective address
#define FETCH_EA(operand) (operand)->last_ea = (operand)->fetch_ea_func(operand)

// Get/Set the operand's value, the stored effective address will be used
#define GET(operand) (operand)->get_value_func((operand))
#define SET(operand, value) (operand)->set_value_func((operand), (value))

// Fetch the operand's effective address and then get/set its value, in one call
#define FETCH_EA_AND_GET(operand) (operand_fetch_ea_and_get(operand))
#define FETCH_EA_AND_SET(operand, value) (operand_fetch_ea_and_set((operand), (value)))

// Effective address resolution function
//
// Calling such a function might trigger a data fetch and advance the program counter
// so it must not be done more than once per instruction call.
typedef uint32_t(*FetchEAFunc)(struct Operand* o);

// Read/Write functions to access an operand's data after its effective address has been computed
//
// Can be called as many times as necessary.
typedef uint32_t(*GetValueFunc)(struct Operand* o);
typedef void(*SetValueFunc)(struct Operand* o, uint32_t value);

// Pre/Post instruction action
typedef void(*Action)(struct Operand* this);

typedef enum
{
    DataRegister,
    AddressRegister,
    AddressRegisterIndirect,
    AddressRegisterIndirectPostInc,
    AddressRegisterIndirectPreDec,
    AddressRegisterIndirectDisplacement,
    AddressRegisterIndirectIndexed,
    AbsoluteShort,
    AbsoluteLong,
    ProgramCounterDisplacement,
    ProgramCounterIndexed,
    Immediate,

    Value,
    BranchingOffset,

    Unsupported
} OperandType;

typedef struct Operand
{
    // The instruction that the operand instance is bound to
    struct Instruction* instruction;

    OperandType type;

    // Last effective address computed
    uint32_t last_ea;

    // Compute and store the operand's effective address
    FetchEAFunc fetch_ea_func;

    // Get/Set the operand's value
    GetValueFunc get_value_func;
    SetValueFunc set_value_func;

    Action pre_func;
    Action post_func;

    int n;
} Operand;

int operand_tostring(Operand* operand, char* buffer);

Operand* operand_make_data_register(int n, struct Instruction*); // TODO put instr first to be consistent with the order modules
Operand* operand_make_address_register(int n, struct Instruction*);
Operand* operand_make_address_register_indirect(int n, struct Instruction*);
Operand* operand_make_address_register_indirect_predec(int n, struct Instruction*);
Operand* operand_make_address_register_indirect_postinc(int n, struct Instruction*);
Operand* operand_make_address_register_indirect_displacement(int n, struct Instruction*);
Operand* operand_make_address_register_indirect_index(int n, struct Instruction*);
Operand* operand_make_immediate_value(Size, struct Instruction*);
Operand* operand_make_absolute_short(struct Instruction*);
Operand* operand_make_absolute_long(struct Instruction*);
Operand* operand_make_pc_displacement(struct Instruction*);
Operand* operand_make_pc_index(struct Instruction*);
Operand* operand_make_value(int value, struct Instruction*);
Operand* operand_make_branching_offset(struct Instruction*, Size size);

Size operand_size(uint8_t pattern);
Size operand_size2(uint8_t pattern);
Size operand_size3(uint8_t pattern); // TODO how to name this?

uint8_t operand_sign_extension(uint8_t pattern);

int operand_length(Operand*);

// Return the number of cycles required to compute an effective address
int operand_get_cycles(Operand*);

Operand* operand_make(uint16_t pattern, struct Instruction* instr);
void operand_free(Operand* instr);

uint32_t operand_fetch_ea_and_get(Operand*);
void operand_fetch_ea_and_set(Operand*, uint32_t);
