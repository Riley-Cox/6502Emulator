#include "defines.h"
#include <math.h>

int main(int argc, char *argv[]){
  int file;
	reset(); // Initialize cpu registers
  file = loadMem(argv[1]); 
  if (!file) {
    return 0;
  }
  else{
  execute();   

	



  return 0;
  }
}
