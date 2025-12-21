#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

#ifndef _DECODE_H
#define _DECODE_H

#define OPCODE 0xFF0000
#define OPERAND 0x00FFFF

typedef void (*op_handler_t)(reg *cpu);

typedef struct {
  uint8_t opcode;
  uint16_t operands;
} instruction;

void instructionMasking(uint32_t instr);

void opAdd(reg *cpu, int value);
  void opAddImm(reg *cpu, instruction *operand);
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
  void opEORImm(reg *cpu);
  void opEORZ(reg *cpu);
  void opEORZX(reg *cpu);
  void opEORAbs(reg *cpu);
  void opEORAbsX(reg *cpu);
  void opEORAbsY(reg *cpu);
  void opEORIndirX(reg *cpu);
  void opEORIndirY(reg *cpu);

void opINC(reg *cpu, int value);
  void opINCZ(*reg);
  void opINCZX(*reg);
  void opINCAbs(*reg);
  void opINCAbsX(*reg);

void opINCX(reg *cpu, int value);

void opINCY(reg *cpu, int value);

void opJMP(reg *cpu, int value);
  void opJMPAbs(reg *cpu);
  void opJMPIndir(reg *cpu);

void opJSR(reg *cpu, int value);

  void opLDAImm(reg *cpu);
  void opLDAZ(reg *cpu);
  void opLDAZX(reg *cpu);
  void opLDAAbs(reg *cpu);
  void opLDAAbsX(reg *cpu);
  void opLDAAbsY(reg *cpu);
  void opLDAIndirX(reg *cpu);
  void opLDAIndirY(reg *cpu);

  void opLDXImm (reg*cpu);
  void opLDXZ (reg*cpu);
  void opLDXZY (reg*cpu);
  void opLDXAbs (reg*cpu);
  void opLDXAbsY (reg*cpu);

  void opLDYImm(reg *cpu);
  void opLDYZ(reg *cpu);
  void opLDYZX(reg *cpu);
  void opLDYAbs(reg *cpu);
  void opLDYAbsX(reg *cpu);

void opLSR(reg *cpu, int value);
  void opLSRAcc(reg *cpu);
  void opLSRZ(reg *cpu);
  void opLSRZX(reg *cpu);
  void opLSRAbs(reg *cpu);
  void opLSRAbsX(reg *cpu);

void opNOP();

void opORA(reg *cpu, int value);
  void opORAImm(reg *cpu);
  void opORAZ(reg *cpu);
  void opORAZX(reg *cpu);
  void opORAAbs(reg *cpu);
  void opORAAbsX(reg *cpu);
  void opORAAbsY(reg *cpu);
  void opORAIndirX(reg *cpu);
  void opORAIndirY(reg *cpu);

void opPHA(reg *cpu);

void opPHP(reg *cpu);

void opPLA(reg *cpu);

void opPLP(reg *cpu);

void opROL(reg *cpu, int value);
  void opROLAcc(reg *cpu);
  void opROLZ(reg *cpu);
  void opROLZX(reg *cpu);
  void opROLAbs(reg *cpu);
  void opROLAbsX(reg *cpu);

void opROR(reg *cpu, int value);
  void opRORAcc(reg *cpu); 
  void opRORZ(reg *cpu); 
  void opRORZX(reg *cpu); 
  void opRORAbs(reg *cpu); 
  void opRORAbsX(reg *cpu); 

void opRTI(reg *cpu);

void opRTS(reg *cpu);

void opSBC(reg *cpu, int value);
  void opSBCImm(reg *cpu);
  void opSBCZ(reg *cpu);
  void opSBCZX(reg *cpu);
  void opSBCAbs(reg *cpu);
  void opSBCAbsX(reg *cpu);
  void opSBCAbsY(reg *cpu);
  void opSBCIndirX(reg *cpu);
  void opSBCIndirY(reg *cpu);

void opSEC(reg *cpu);

void opSEI(reg *cpu);

  void opSTAZ(reg *cpu);
  void opSTAZX(reg *cpu);
  void opSTAAbs(reg *cpu);
  void opSTAAbsX(reg *cpu);
  void opSTAAbsY(reg *cpu);
  void opSTAIndirX(reg *cpu);
  void opSTAIndirY(reg *cpu);

void opSTXZ(reg *cpu);
void opSTXZY(reg *cpu);
void opSTXAbs(reg *cpu);

void opTAX(reg *cpu);

void opTAY(reg *cpu);

void opTSX(reg *cpu);

void opTXA(reg *cpu);

void TYA(reg *cpu);






  
  

  















#endif
