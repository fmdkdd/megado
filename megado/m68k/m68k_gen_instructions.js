const u = require('./m68k_gen_utils');
const op = require('./m68k_gen_operands');

// Generators are function that return an object with:
//   - src: source operand
//   - dst: destination operand
//   - mnemonics: instruction name
//   - code: instruction code

module.exports.gen_add = (opcode) =>
{
    const size = u.size2[u.bits(opcode, 7, 6)];
    const reg = op.data_reg(u.bits(opcode, 11, 9), size);
    const ea = op.operand_from_pattern(u.bits(opcode, 5, 0), size);

    const direction = u.bit(opcode, 8);
    const src = direction === 0 ? ea : reg;
    const dst = direction === 0 ? reg : ea;

    return {
        mnemonics: `ADD.${size} ${src.str()}, ${dst.str()}`,
        src, dst,
        code: `
            ${u.size_types[size]} a = ${src.get()};
            ${u.size_types[size]} b = ${dst.get()};
            ${dst.set('a + b')};

            uint32_t result = ${dst.get()};
            CARRY_SET(ctx, CHECK_CARRY_ADD(a, b, ${u.size_enum[size]}));
            OVERFLOW_SET(ctx, CHECK_OVERFLOW_ADD(a, b, ${u.size_enum[size]}));
            ZERO_SET(ctx, result == 0);
            NEGATIVE_SET(ctx, BIT(result, ${u.size_enum[size]} - 1));
            EXTENDED_SET(ctx, CARRY(ctx));`
    };
};

module.exports.gen_bset = (opcode) =>
{
    // Size is long only when the destination is a data register, byte otherwise
    const size = u.bits(opcode, 5, 3) === 0 ? 2 : 0;

    const src = op.data_reg(u.bits(opcode, 11, 9), size);
    const dst = op.operand_from_pattern(u.bits(opcode, 5, 0), size);

    return {
        mnemonics: `BSET.${size} ${src.str()}, ${dst.str()}`,
        src, dst,
        code: `
            uint8_t bit = ${src.get()} % ${u.size_values[size]};
            uint32_t initial = ${dst.get()};
            ${src.set('BIT_SET(initial, bit)')};

            ZERO_SET(ctx, BIT(initial, bit) == 0);`
    };
};

module.exports.gen_move = (opcode) =>
{
    const size = u.size3[u.bits(opcode, 13, 12)];
    const src = op.operand_from_pattern(u.bits(opcode, 5, 0), size);
    const dst = op.operand_from_pattern((u.bits(opcode, 8, 6) << 3) | u.bits(opcode, 11, 9), size); // The destination mode is swapped

    return {
        mnemonics: `MOVE.${size} ${src.str()}, ${dst.str()}`,
        src, dst,
        code: `
            ${u.size_types[size]} value = ${src.get()};
            ${dst.set('value')};

            CARRY_SET(ctx, false);
            OVERFLOW_SET(ctx, false);
            ZERO_SET(ctx, value == 0);
            NEGATIVE_SET(ctx, BIT(value, ${u.size_values[size] - 1}) == 1); `
    };
};
