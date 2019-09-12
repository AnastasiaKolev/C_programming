#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * getPair(char *pair){
  char *key, *value;
  kvpair_t *kvpair = malloc(sizeof(*kvpair));

  key = strsep(&pair, "=");
  value = strsep(&pair, "\n");

  kvpair->key = strdup(key);
  kvpair->value = strdup(value);

  return kvpair;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE *f = fopen(fname, "r");
  if(f == NULL) {
    perror("fopen");
    fprintf(stderr, "Failed to open %s\n", fname);
    exit(0);
  }

  kvarray_t *kvarray = malloc(sizeof(*kvarray));
  kvarray->kvpairs = NULL;
  kvarray->numPairs = 0;
  char *pair = NULL;
  size_t sz = 0;

  while(getline(&pair, &sz, f) > 0) {
    kvpair_t *currpair = getPair(pair);
    kvarray->kvpairs = realloc(kvarray->kvpairs,
			       (kvarray->numPairs + 1) * sizeof(*kvarray->kvpairs));
    kvarray->kvpairs[kvarray->numPairs] = currpair;
    kvarray->numPairs++;
    free(pair);
    pair = NULL;
  }
  free(pair);

  if (fclose(f) != 0) {
    perror("fclose");
    fprintf(stderr, "Failed to close %s\n", fname);
    return NULL;
  }
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->numPairs; i++) {
    free(pairs->kvpairs[i]->key);
    free(pairs->kvpairs[i]->value);
    free(pairs->kvpairs[i]);
  }
  free(pairs->kvpairs);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i=0; i<pairs->numPairs; i++) {
    printf("key = '%s' value = '%s'\n", pairs->kvpairs[i]->key, pairs->kvpairs[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i = 0; i < pairs->numPairs; i++) {
    if (strcmp(pairs->kvpairs[i]->key, key) == 0) {
      return pairs->kvpairs[i]->value;
    }
  }
  return NULL;
}
