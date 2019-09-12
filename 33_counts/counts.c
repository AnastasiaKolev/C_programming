#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * counts = malloc(sizeof(*counts));
  counts->count_array = NULL;
  counts->sizeArr = 0;
  counts->sizeUn = 0;
  return counts;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name == NULL) {
    c->sizeUn++;
  }
  else {
    int count = 0;
    for (int i = 0; i < c->sizeArr; i++) {
      if (strcmp(name, c->count_array[i]->str) == 0) {
	c->count_array[i]->count++;
	count++;
      }
    }
    if (count == 0) {
      c->sizeArr++;
      c->count_array = realloc(c->count_array, c->sizeArr * sizeof(*c->count_array));
      c->count_array[c->sizeArr-1] = malloc(sizeof(one_count_t));
      c->count_array[c->sizeArr-1]->str = name;
      c->count_array[c->sizeArr-1]->count = 1;
    }
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for (int i = 0; i < c->sizeArr; i++) {
    fprintf(outFile, "%s: %d\n", c->count_array[i]->str, c->count_array[i]->count);
  }
  if (c->sizeUn > 0) {
    fprintf(outFile, "<unknown>: %d\n", c->sizeUn);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i = 0; i < c->sizeArr; i++) {
    free(c->count_array[i]);
  }
  free(c->count_array);
  free(c);
}
