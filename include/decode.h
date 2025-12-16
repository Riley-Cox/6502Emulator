#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

#ifndef _DECODE_H
#define _DECODE_H

#define OPCODE 0xF00
#define OPERAND 0x0FF

typedef void (*op_handler_t)(reg *cpu);

typedef struct {
  uint8_t opcode;
  uint16_t operands;
} instruction;

void instructionMasking(uint32_t instr);

void opAdd(reg *cpu, int value);
  void opAddImm(reg *cpu);
  void opAddZX(reg *cpu);
  void opAddZY(reg *cpu);
  void opAndAbs(reg *cpu);
  void opAddAbsX(reg *cpu);
  void opAddAbsY(reg *cpu);
  void opAddIndirX(reg *cpu);
  void opAddIndirY(reg *cpu);

void opAnd(reg *cpu, int value);
  void opAndImm(reg *cpu);
  void opAndZX(reg *cpu);
  void opAndZY(reg *cpu);
  void opAndAbs(reg *cpu);
  void opAndAbsX(reg *cpu);
  void opAndAbsY(reg *cpu);
  void opAndIndirX(reg *cpu);
  void opAndIndirY(reg *cpu);

void opASL(reg *cpu, int value);
  void opASLAcu(reg *cpu);
  void opASLZ(reg *cpu);
  void opASLZX(reg *cpu);
  void opASLAbs(reg *cpu);
  void opASLAbsX(reg *cpu);

void opBCC(reg *cpu, int value);

void opBCS(reg *cpu, int value);

void opBIT(reg *cpu, int value);
  void opBITZ(reg *cpu);
  void opBITAbs(reg *cpu);

void opBMI(reg *cpu, int value);

void opBNE(reg *cpu, int value);

void opBPL(reg *cpu, int value);

void opBRK(reg *cpu);

void opBVC(reg *cpu, int value);

void opCLC(reg *cpu);

void opCLD(reg *cpu);

void opCLI(reg *cpu);

void opCLV(reg *cpu);

void opCMP(reg *cpu, int value);
  void opCMPImm(reg *cpu);
  void opCMPZ(reg *cpu);
  void opCMPZX(reg *cpu);
  void opCMPAbs(reg *cpu);
  void opCMPAbsX(reg *cpu);
  void opCMPAbsY(reg *cpu);
  void opCMPIndirX(reg *cpu);
  void opCMPIndirY(reg *cpu);

void opCPX(reg *cpu, int value);
  void opCPXImm(reg *cpu);
  void opCPXZ(reg *cpu);
  void opCPXAb(reg *cpu);

void opCPY(reg *cpu, int value);
  void opCPYImm(reg *cpu);
  void opCPYZ(reg *cpu);
  void opCPYAbs(reg *cpu);

void opDEC(reg *cpu, int value);
  void opDECZ(reg *cpu);
  void opDECZX(reg *cpu);
  void opDECAbs(reg *cpu);
  void opDECAbsX(reg *cpu);

void opDECY(reg *cpu, int value);

void opDECX(reg *cpu, int value);

void opEOR(reg *cpu, int value);
  

#endif
