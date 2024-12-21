#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#ifndef _DEFINES_H
#define _DEFINES_h

#define AS 16 * 1024
#define SP 256

//Opcodes
//LDA instruction  
#define LDA_I 0xA9
#define LDA_Z 0xA5
#define LDA_ZX 0xB5
#define LDA_A 0xAD
#define LDA_AX 0xBD
#define LDA_AY 0xB9
#define LDA_INX 0xA1
#define LDA_INY 0xB1
//LDX instruction  
#define LDX_I 0xA2
#define LDX_Z 0xA6
#define LDX_ZY 0xB6
#define LDX_A 0xAE
#define LDX_AY 0xBE
//LDY instruction 
#define LDY_I 0xA0
#define LDY_Z 0xA4
#define LDY_ZX 0xB4
#define LDY_A 0xAC
#define LDY_AX 0xBC
//LSR instruction 
#define LSR_AC 0x4A
#define LSR_Z 0x46
#define LSR_ZX 0x56
#define LSR_A 0x4E
#define LSR_AX 0x5E
//NOP instruction 
#define NOP 0xEA
//ORA instruction 
#define ORA_I 0x09
#define ORA_Z 0x05
#define ORA_ZX 0x15
#define ORA_A 0x0D
#define ORA_AX 0x1D
#define ORA_AY 0x19
#define ORA_IX 0x01
#define ORA_IY 0x11
//PHA instruction 
#define PHA 0x48
//PHP instruction 
#define PHP 0x08
//PLA instruction 
#define PLA 0x68
//PLP instruction 
#define PLP 0x28
//ROL instruction 
#define ROL_AC 0x2A
#define ROL_Z 0x26
#define ROL_ZX 0x36
#define ROL_A 0x2E
#define ROL_AX 0x3E
//ROR instruction 
#define ROR_AC 0x6A
#define ROR_Z 0x66
#define ROR_ZX 0x76
#define ROR_A 0x6E
#define ROR_AX 0x7E
//RTI instruction 
#define RTI 0x40
//RTS instruction 
#define RTS 0x60
//SBC instruction 
#define SBC_I 0xE9
#define SBC_Z 0xE5
#define SBC_ZX 0xF5
#define SBC_A 0xED
#define SBC_AX 0xFD
#define SBC_AY 0xF9
#define SBC_IX 0xE1
#define SBC_IY 0xF1
//SEC instruction 
#define SEC 0x38
//SED instruction 
#define SED 0xF8
//SEI instruction 
#define SEI 0x78
//STA instruction 
#define STA_Z 0x85
#define STA_ZX 0x95
#define STA_A 0x8D
#define STA_AX 0x9D
#define STA_AY 0x99
#define STA_IX 0x81
#define STA_IY 0x91
//STX instruction 
#define STX_Z 0x86
#define STX_ZY 0x96
#define STX_A 0x8E
//STY instruction
#define STY_Z 0x84
#define STY_ZX 0x94
#define STY_A 0x8C
//TAX instruction 
#define TAX 0xAA
//TAY instruction 
#define TAY 0xA8
//TSX instruction 
#define TSX 0xBA
//TXA instruction 
#define TXA 0x8A
//TXS instruction 
#define TXS 0x9A
//TYA instruction
#define TYA 0x98
//ADC instruction 
#define ADC_I 0x69
#define ADC_Z 0x65
#define ADC_ZX 0x75
#define ADC_A 0x6D
#define ADC_AX 0x7D
#define ADC_AY 0x79
#define ADC_IX 0x61
#define ADC_IY 0x71
//AND instruction 











typedef struct {
	uint8_t memorySpace[AS];
	uint8_t stackSpace[SP];
} mem;

typedef struct {
	uint8_t stackPointer;
	uint16_t programCounter;
	uint8_t statusRegister;
	uint8_t indexRegisterX;
	uint8_t indexRegisterY;
	uint8_t accumRegister;
} reg;

typedef struct {
	uint8_t dataBus;
	uint16_t addrBus;
	bool busEnable; //Active high, when asserted the processor can drive the data line
} bus;
	

//Function Declarations

/*************************
* reset - resets the CPU to its initial state
* cpu - register variable that holds essential regsiters
**************************
*/
void reset();
/************************
* push - pushes data onto the stack and decrements stack pointer
* data - data to be pushed onto stack
*************************/
void push(uint8_t data);

/************************
* pop - pops item off stack and increments the stack pointer
* returns the data from the stack
*************************/
uint8_t pop();

/************************
* execute - main execute loop to take execute next instruction
*************************/
void execute();

/************************
* fetch - fetches the next instruction from memory to be executed
* returns the instruction of type mem 
*************************/
uint8_t fetch();







#endif


