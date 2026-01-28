#include "defines.h"
#include "decode.h"
#include "bpl.h"

void opBPL(reg *cpu, uint8_t value){
  if(!(cpu->statusRegister & 0xE0))
    cpu->programCounter = cpu->programCounter - 1 + value;
}
