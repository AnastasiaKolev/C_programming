#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t * c = createCounts();
  FILE * f = fopen( filename, "r");
  if (f == NULL) return NULL;
  char * pair = NULL;
  size_t sz = 0;
  while (getline(&pair, &sz, f) > 0) {
    char * line = strchr(pair, '\n');
    if (line != NULL) *line = '\0';

    char * value = lookupValue(kvPairs, pair);
    addCount(c, value);
  }
  free(pair);
  if (fclose(f) != 0 ) return NULL;
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if (argc < 2) {
    fprintf(stderr, "Usage: ./count_values kvs1.txt list1a.txt list1b.txt\n");
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);
  //count from 2 to argc (call the number you count i)
  for (int i = 2; i < argc; i++) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv);
    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)
    FILE * f= fopen(outName,"w");
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    if (fclose(f) != 0) {
      perror("fclose");
      fprintf(stderr, "Failed close %s\n", outName);
      return EXIT_FAILURE;
    }
    //free the memory for outName and c
    free(outName);
    freeCounts(c);

  }
  //free the memory for kv
  freeKVs(kv);
    
  return EXIT_SUCCESS;
}
