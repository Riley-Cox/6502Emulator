#include "defines.h"
#include "decode.h"
#include "bit.h"

void opBIT(reg *cpu, uint16_t location){
  uint8_t value = readByte(location);
  cpu->statusRegister |= (|(value & cpu->accumRegister));
  cpu->statusRegister |= (value & 0xE0);
  cpu->statusRegister |= (value & 0x80);
}
