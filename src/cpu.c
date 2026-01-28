#include <stdio.h>
#include <stdlib.h>
#include "defines.h"




void reset(reg *cpuReg, mem *memory){
	cpuReg->programCounter = 0x0600;
	cpuReg->stackPointer = 0xFF;
	cpuReg->statusRegister |= ~0xFB; //Set interrupt disable
	cpuReg->statusRegister &= 0xF7;
	cpuReg->accumRegister = 0x00;
	cpuReg->indexRegisterX = 0x00;
	cpuReg->indexRegisterY = 0x00;	
	
	for(int i = 0; i < AS; i++){
		memory->memorySpace[i] = 0;
	}
}

//Stack push function
void push(uint8_t data, reg *cpuReg, mem *memory){
	memory->stackSpace[cpuReg->stackPointer] = data;
	cpuReg->stackPointer -= 0x1;
}

//Stack pop function
uint8_t pop(reg *cpuReg, mem *memory){
	uint8_t data = memory->stackSpace[cpuReg->stackPointer];
	cpuReg->stackPointer += 0x1;
	return data;
}	


//Fetch instructions 
void fetchOpcode(reg *cpuReg, mem *memory, instruction *operand){
  operand->opcode = memory->memorySpace[cpuReg->programCounter];
  cpuReg->programCounter += 1;
}

void fetchOperand(reg *cpuReg, mem *memory, instruction *operand, int bytesToFetch){
 for (int i = 0; i < bytesToFetch; i++){
    operand->operands[i] = memory->memorySpace[cpuReg->programCounter];
    cpuReg->programCounter += 1;
  } 
}

void decodeInstruction(reg *cpuReg, mem *memory, instruction *operand){
  switch(operand->opcode){
    case(ADCIMM):
      fetchOperand(cpuReg, memory, operand, 1);
      opAddImm(cpuReg, operand) 
  }
}


uint8_t readByte(uint16_t location){
  mem memory;
  uint16_t buf = (location << 8) & (location >> 8); 
  return memory.memorySpace[buf]; 
}

void writeByte(uint16_t location, uint8_t data){
  mem memory; 
  uint16_t buf = (location << 8) & (location >> 8);
  memory.memorySpace[buf] = value;
}





