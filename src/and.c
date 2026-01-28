#include "and.h"

void opAND(reg *cpu, uint8_t value){
  cpu->accumRegister = cpu->accumRegister & value;
  setFlags(cpu->accumRegister); //Placeholder
}

void opANDImm(reg *cpu, instruction *operand){
  opAND(cpu, (operand->operands & 0x00FF));
}

void opANDZX(reg *cpu, instruction *operand){
  opAND(cpu, zeroX(cpu, operand));
}

void opANDAbs(reg *cpu, instruction *operand){
  opAND(cpu, abs(cpu, operand));
}

void opANDAbsX(reg *cpu, instruction *operand){
  opAND(cpu, absX(cpu, operand));
}

void opANDIndirX(reg *cpu, instruction *operand){
  opAND(cpu, indirX(cpu, operand));
}

void opANDIndirY(reg *cpu, instruction *operand){
  opAND(cpu, indirY(cpu, operand));
}
