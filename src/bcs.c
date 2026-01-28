#include "bcs.h"

void opBCS(reg *cpu, uint8_t value){
  if(!(cpu->statusRegister & 0x01))
    (cpu->programCounter = cpu->programCounter - 1 + value);
}
