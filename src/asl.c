#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "decode.h"
#include "asl.h"


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

void opASLAccu(reg *cpu, instruction *operand){
  opASL(cpu,cpu->accumRegister); 
}
