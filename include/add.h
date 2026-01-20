#include <stdio.h>
#include <stdlib.h>
#include "decode.h"
#include "defines.h"


void opAND(reg *cpu, uint8_t value);
void opANDImm(reg*cpu, instruction *operand);
void opANDZX(reg*cpu, instruction *operand);
void opANDAbs(reg*cpu, instruction *operand);
void opANDAbsX(reg*cpu, instruction *operand);
void opANDIndirX(reg*cpu, instruction *operand);
void opANDIndirY(reg*cpu, instruction *operand);
