#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "decode.h"
#include "bcc.h"

void opBCC(reg *cpu, uint8_t value){
  if(cpu->statusRegister & 0x01)
    cpu->programCounter = cpu->programCounter - 1 + value;
}
