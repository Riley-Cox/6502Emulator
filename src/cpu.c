#include <stdio.h>
#include <stdlib.h>
#include "defines.h"




void reset(reg *cpuReg, mem *memory){
	cpuReg->programCounter = 0x0000;
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

//Main code loop, 
void execute(){
}

//Fetch instructions 
uint32_t fetch(reg *cpuReg, mem *memory){
  uint8_t inst;

  inst = memory->memorySpace[cpuReg->programCounter];
  cpuReg->programCounter += 1;
}

uint8_t readByte(mem *memory, uint16_t location){
  uint16_t buf = (location << 8) & (location >> 8); 
  return memory->memorySpace[buf]; 

