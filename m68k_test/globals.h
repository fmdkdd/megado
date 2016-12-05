#pragma once

#include <m68k/m68k.h>

// This extends minunit to print asserted values in hexadecimal
#define mu_assert_int_eq_hex(expected, result) MU__SAFE_BLOCK(\
	int minunit_tmp_e;\
	int minunit_tmp_r;\
	minunit_assert++;\
	minunit_tmp_e = (expected);\
	minunit_tmp_r = (result);\
	if (minunit_tmp_e != minunit_tmp_r) {\
		snprintf(minunit_last_message, MINUNIT_MESSAGE_LEN, "%s failed:\n\t%s:%d: %#08X expected but was %#08X", __func__, __FILE__, __LINE__, minunit_tmp_e, minunit_tmp_r);\
		minunit_status = 1;\
		return;\
	} else {\
		printf(".");\
	}\
)

#define DATA(n, x) m->data_registers[n] = x
#define DATA_CHECK(n, x) mu_assert_int_eq_hex(x, m->data_registers[n])
#define RUN(opcode) m68k_execute(m, parse_bin(opcode))

extern M68k* m;

void setup();
void teardown();
