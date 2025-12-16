#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
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

  while ((read = getline(&line, &len, fp)) != -1) {
    printf("Retrieved line of length %zu:\n", read);
    char *data = strchr(line, ':');
    if (!data)
      continue;
    data++;
    while (*data == ' ')
      data++;
    memory->memorySpace[i] = atoi(data);
    i++;
  }

  fclose(fp);
  if (line)
      free(line);
  return 1;
}
