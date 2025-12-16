#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "defines.h"

int main(int argc, char *argv[]){
  int file;
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
  execute();   

	


  free(cpuReg);
  free(memory);
  return 0;
  }
}
