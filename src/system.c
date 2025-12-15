#include "defines.h"
#include <stdio.h>

int loadMem(char *filename){
  FILE *fp = fopen(fileName, "rt");
  char *line;
  size_t len = 0;
  ssize_t read;
  int i, j, k;
  if (fp == NULL) {
    printf("File does not exist");
    return 0;
  }

  while ((read = getline(&line, &len, filename)) != -1) {
    printf("Retrieved line of length %zu:\n", read);
    printf("%s", line);
  }

  fclose(filename);
  if (line)
      free(line);
  return 1;
}
