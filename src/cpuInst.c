#include "defines.h"

reg cpuReg;
mem memory;
bus Bus;

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
	cpuReg.stackPointer--;
}

uint8_t pop(){
	uint8_t data = memory.stackSpace[cpuReg.stackPointer];
	cpuReg.stackPointer++;
	return data;
}	

void execute(){ // on a clock cycle we need to fetch the next instruction from memory and execute it 
	uint8_t fetchedInst;
	while(1){//?? This isn't verilog so idk how to model the clock pulse
		fetchedInst = fetch();
		(void)fetchedInst;
		switch (fetchedInst){
			
	}	
}
}

uint8_t fetch(){
	uint8_t buff;
	Bus.addrBus = memory.memorySpace[cpuReg.programCounter];
		//Will have to do some waiting to grab data from ROM
		if(!Bus.busEnable){
			buff = Bus.dataBus; //Grab data off the data bus after asking for it from the address location
			cpuReg.programCounter++;
			return buff;
		}
		else
			return 0;
}
	
	
