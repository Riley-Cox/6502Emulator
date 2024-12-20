#include "defines.h"

reg cpuReg;
mem memory;
inst cpuInst;

void reset(){
	cpuReg.programCounter = 0xFFFC;
	cpuReg.stackPointer = 0xFF;
	cpuReg.statusRegister |= ~0xFB; //Set interrupt disable
	cpuReg.statusRegister &= 0xF7;
	cpuReg.accumRegister = 0x00;
	cpuReg.indexRegisterX = 0x00;
	cpuReg.indexRegisterY = 0x00;	
	
	for(int i = 0; i < AS; i++){
		memory.memorySpace[i] = 0;
	}
}

void push(uint8_t data){
	memory.stackSpace[cpuReg.stackPointer] = data;
	cpuReg.stackPointer -= 0x1;
}

uint8_t pop(){
	uint8_t data = memory.stackSpace[cpuReg.stackPointer];
	cpuReg.stackPointer += 0x1;
	return data;
}	

void execute(){
	mem fetchedInst;
	while(1){
		fetchedInst = fetch();
	}	
}

uint8_t fetch(){
	uint8_t buff;
	buff = memory.memorySpace[cpuReg.programCounter];
	cpuReg.programCounter += 0x1;
	return buff;	
}
	
	
