#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "defines.h"
#include "decode.h"


void opASL(reg *cpu, bool isMem, uint16_t location);
void opASLAccu(reg *cpu, instruction *operand);
