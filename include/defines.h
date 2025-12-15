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
void execute(mem inst);

/************************
* fetch - fetches the next instruction from memory to be executed
* returns the instruction of type mem 
*************************/
uint8_t fetch();

/************************
* loadMem - loads the program into memory to allow for fetching
*************************/
int loadMem(char *fileName);






#endif


