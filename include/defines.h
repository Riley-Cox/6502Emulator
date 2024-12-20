#include <stdio.h>
#include <stdint.h>
#include <math.h>

#ifndef _DEFINES_H
#define _DEFINES_h

#define AS 16 * 1024
#define SP 256


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



//Function Declarations

/*************************
* reset - resets the CPU to its initial state
* cpu - register variable that holds essential regsiters
**************************
*/
void reset();

void push(uint8_t data);

uint8_t pop();








#endif


