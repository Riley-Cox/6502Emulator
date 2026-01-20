#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "defines.h"
#include "decode.h"



//-------------------------HELPER FUNCTIONS---------------------------
uint8_t zeroX(reg *cpu, instruction *operand){
  uint8_t value = operand->operands + cpu->indexRegisterX;
  value = value & 0x00FF;
  return value;
}

uint8_t abs(reg *cpu, instruction *operand){
  uint8_t value = readByte(operand->operands);
  return value;
}

uint8_t absX(reg *cpu, instruction *operand){
  uint16_t location = operand->operands + cpu->indexRegisterX;
  uint8_t value = readByte(location);
  return value;
}

uint8_t absY(reg *cpu, instruction *operand){
  uin16_t location = operand->operands + cpu->indexRegisterY;
  uint8_t value = readByte(location);
  return value;
}

uint8_t indirX(reg *cpu, instruction *operand){
  uint16_t lookup = readByte(operand->operands + cpu->indexRegisterX);
  lookup = (lookup << 8) & readByte(operand->operands + 1 + cpu->indexRegisterX);
  uint8_t value = readByte(lookup);
  return value;
}

uint8_t indirY(reg *cpu, instruction *operand){
  uint16_t lookup = (readByte(operand->operands) << 8) & (readByte(operand->operands + 1));
  uint8_t value = readByte(lookup);
  return value;
}
//-------------------------------------------------------------------



//----------------------------OPCODE INSTRUCTIONS----------------------
void opAdd(reg *cpu, uint8_t value){
  cpu->accumRegister += (value + (cpu->statusRegister & 0x01));
  setFlags(cpu->accumRegister);
}

void opAND(reg *cpu, uint8_t value){
  cpu->accumRegister & value;
  setFlags(cpu->accumRegister);
}
// I think we need to create a write byte helper function here 
void opASL(reg *cpu, bool isMem, uint16_t location){
  if(isMem){
    if(readByte(location) & 0x80)
      cpu->statusRegister |= 0x01;
    uint8_t value = readByte(location) << 1;
    writeByte(location, value);
  }  
  else{
    if(cpu->accumRegister & 0x80)
      cpu->statusRegister |= 0x01;
    cpu->accumRegister = cpu->accumRegister << 1;
  }
}
//TODO: Might need to look more closely on the branching to determine how far back the PC needs to be when we add the value to it
void opBCC(reg *cpu, uin8_t value){
  if(cpu->statusRegister & 0x01)
    (cpu->programCounter = cpu->programCounter - 1 + value);
}

void opBCS(reg *cpu, uint8_t value){
  if(!(cpu->statusRegister & 0x01))
    (cpu->programCounter = cpu->programCounter - 1 + value);
}

void opBEQ(reg *cpu, uint8_t value){
  if(!(cpu->statusRegister & 0x02))
    (cpu->programCounter = cpu->programCounter - 1 + value);
}

void opBIT(reg *cpu, uint16_t location){
  uint8_t value = readByte(location);
  cpu->statusRegister |= (|(value & cpu->accumRegister));
  cpu->statusRegister |= (value & 0xE0);
  cpu->statusRegister |= (value & 0x80);
}

void opBMI(reg *cpu, uint8_t value){
  if(cpu->statusRegister & 0xE0)
    cpu->programCounter = cpu->programCounter - 1 + value;
}

void opBNE(reg *cpu, uint8_t value){
  if(!(cpu->statusRegister & 0x80))
    cpu->programCounter = cpu->programCounter - 1 + value;
}

void opBPL(reg *cpu, uint8_t value){
  if(!(cpu->statusRegister & 0xE0))
    cpu->programCounter = cpu->programCounter - 1 + value;
}

void opBRK(reg *cpu){

}

void opBVC(reg *cpu, uint8_t value){

}
//----------------------------------------------------------------------


//----------------------------ADDRESSING MODES--------------------------
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

void opASLAccu(reg *cpu, instruction *operand){
  opASL(cpu,cpu->accumRegister); 
}


