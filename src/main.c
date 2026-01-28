#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "defines.h"
#include "decode.h"

int main(int argc, char *argv[]){
  int file;
  //reg *cpuReg = (reg *) malloc(sizeof(reg));
 //mem *memory = (mem *) malloc(sizeof(mem));
  reg *cpuReg;
  mem *memory;


	reset(cpuReg); // Initialize cpu registers
  file = loadMem(argv[1], memory); 
  if (!file) {
    return 0;
  }
  else{
  while (1){
    inst = fetch(cpuReg, memory);
    if(inst == 0)
     exit(1);   
    decode(inst);
    execute();   
  }

	


  return 0;
  }
}
