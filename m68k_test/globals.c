#include "globals.h"

M68k* m = NULL;

void setup()
{
    m = m68k_make();
}

void teardown()
{
    m68k_free(m);
}
