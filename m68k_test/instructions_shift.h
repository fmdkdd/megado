#pragma once

#include <minunit.h>
#include <m68k/m68k.h>

#include "globals.h"

MU_TEST(test_lsl)
{
    DATA(7, 1);
    
    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 1 00 1 01 000"); // LSL.b D7, D0 (1 bit)
    DATA_CHECK(0, 0xFFFFFFFE);
    
    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 1 01 1 01 000"); // LSL.w D7, D0 (1 bit)
    DATA_CHECK(0, 0xFFFFFFFE);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 1 10 1 01 000"); // LSL.l D7, D0 (1 bit)
    DATA_CHECK(0, 0xFFFFFFFE);

    DATA(7, 10);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 1 00 1 01 000"); // LSL.b D7, D0 (10 bits)
    DATA_CHECK(0, 0xFFFFFF00);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 1 01 1 01 000"); // LSL.w D7, D0 (10 bits)
    DATA_CHECK(0, 0xFFFFFC00);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 1 10 1 01 000"); // LSL.l D7, D0 (10 bits)
    DATA_CHECK(0, 0xFFFFFC00);
}

MU_TEST(test_lsr)
{
    DATA(7, 1);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 0 00 1 01 000"); // LSR.b D7, D0 (1 bit)
    DATA_CHECK(0, 0xFFFFFF7F);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 0 01 1 01 000"); // LSR.w D7, D0 (1 bit)
    DATA_CHECK(0, 0xFFFF7FFF);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 0 10 1 01 000"); // LSR.l D7, D0 (1 bit)
    DATA_CHECK(0, 0x7FFFFFFF);

    DATA(7, 10);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 0 00 1 01 000"); // LSR.b D7, D0 (10 bits)
    DATA_CHECK(0, 0xFFFFFF00);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 0 01 1 01 000"); // LSR.w D7, D0 (10 bits)
    DATA_CHECK(0, 0xFFFF003F);

    DATA(0, 0xFFFFFFFF);
    RUN("1110 111 0 10 1 01 000"); // LSR.l D7, D0 (10 bits)
    DATA_CHECK(0, 0x3FFFFF);
}

MU_TEST(test_swap)
{
    DATA(4, 0x1234ABCD);
    RUN("0100100001000 100"); // SWAP D4
    DATA_CHECK(4, 0xABCD1234);
}

MU_TEST_SUITE(test_suite_instructions_shift)
{
    MU_SUITE_CONFIGURE(&setup, &teardown);

    MU_RUN_TEST(test_lsl);
    MU_RUN_TEST(test_lsr);

    MU_RUN_TEST(test_swap);
}
