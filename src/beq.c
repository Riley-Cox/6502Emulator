#include "defines.h"
#include "decode.h"
#include "beq.h"

void opBEQ(reg *cpu, uint8_t value){
  if(!(cpu->statusRegister & 0x02))
    cpu->programCounter = cpu->programCounter - 1 + value;
}
