#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "decode.h"


void opAdd(reg *cpu, int value){
  cpu->accumRegister += value;
  setFlags(cpu->accumRegister)
}

//mask upper 8 bits of the operand and shift left to be used in operation
void opAddImm(reg *cpu, instruction *operand){
  cpu->accumRegister += ((operand->operands & 0xFF00) >> 8)
}

void opAddZX(reg *cpu, instruction *operand){
  int value = ((operand->operands & 0xFF00) >> 8) + cpu->indexRegisterX;
  value = value & 0x00FF;
  opAdd(cpu, value);
} 

void opAddZY(reg *cpu, instruction *operand){
  int value = ((operand->operands & 0xFF00) >> 8) + cpu->indexRegisterY;
  value = value & 0x00FF;
  opAdd(cpu, value);
}

//Need to make a set of functions to be able to read out of memory
void opAddAbs(reg *cpu, instruction *operand){
  int value = 
  opAdd(cpu, value );
}

