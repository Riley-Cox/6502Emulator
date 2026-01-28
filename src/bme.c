#include "defines.h"
#include "decode.h"
#include "bne.h"

void opBNE(reg *cpu, uint8_t value){
  if(!(cpu->statusRegister & 0x80))
    cpu->programCounter = cpu->programCounter - 1 + value;
}
