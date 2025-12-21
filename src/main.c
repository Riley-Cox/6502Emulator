#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "defines.h"
#include "decode.h"

int main(int argc, char *argv[]){
  int file;
  uint32_t 
  reg *cpuReg = (reg *) malloc(sizeof(reg));
  mem *memory = (mem *) malloc(sizeof(mem));
	reset(cpuReg, memory); // Initialize cpu registers
  file = loadMem(argv[1], memory); 
  if (!file) {
    return 0;
    free(cpuReg);
    free(memory);
  }
  else{
  while (1){
    inst = fetch(cpuReg, memory);
    if(inst == 0)
     exit(1);   
    decode(inst);
    execute();   
  }

	


  free(cpuReg);
  free(memory);
  return 0;
  }
}
