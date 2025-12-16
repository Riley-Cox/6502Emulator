#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "defines.h"

int loadMem(char *filename, mem *memory){
  FILE *fp = fopen(filename, "rt");
  char *line;
  size_t len = 0;
  ssize_t read;
  int i = 0;
  if (fp == NULL) {
    printf("File does not exist");
    return 0;
  }

  //Need to seperate instruction address from instruction
  while ((read = getline(&line, &len, fp)) != -1) {
    printf("Retrieved line of length %zu:\n", read);
    memory->memorySpace[i] = atoi(line);
    i++;
  }

  fclose(fp);
  if (line)
      free(line);
  return 1;
}
