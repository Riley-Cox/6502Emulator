#include "add.h"


void opADD(reg* cpu, uint8_t value){
  cpu->accumRegister += (value + (cpu->statusRegister & 0x01));
  setFlags(cpu->accumRegister); //Placeholder until I figure out how I'm gonna set flags
}

void opAddImm(reg *cpu, instruction *operand){
  opAdd(cpu, (operand->operands & 0x00FF));
}

void opAddZX(reg *cpu, instruction *operand){
  opAdd(cpu, zeroX(cpu, operand));
} 

void opAddAbs(reg *cpu, instruction *operand){
  opAdd(cpu, abs(cpu, operand));
}

void opAddAbsX(reg *cpu, instruction *operand){
  opAdd(cpu, absX(cpu, operand));
}

void opAddAbsY(reg *cpu, instruction *operand){
  opAdd(cpu, absY(cpu, operand));
}
//Indexed Indirect - pre index
void opAddIndirX(reg *cpu, instruction *operand){
  opAdd(cpu, indirX(cpu, operand));
}

//Indirect Index - post index
void opAddIndirY(reg *cpu, instruction *operand){
  opAdd(cpu, indriY(cpu, operand));
}
