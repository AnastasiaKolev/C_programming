#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 12
#define MATRIX_SIZE 10

void rotate(char matrix[10][10]) {
  for(int i=0; i<10; i++){
    for(int j=9; j>=0; j--){
      printf("%c", matrix[j][i]);
    }
    printf("\n");
  }
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Wrong number of arguments. Usage: rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }

  // open file
  FILE * f = fopen(argv[1], "r");
  // make sure a file was opened
  if (f == NULL) {
    perror("Could not open file!");
    return EXIT_FAILURE;
  }
  
  // check that the input is correct
  int height = 0; // track how many lines matrix has
  char line[LINE_LENGTH];
  char matrix[MATRIX_SIZE][MATRIX_SIZE];

  while(fgets(line, LINE_LENGTH, f) != NULL) {
    // If line has more than 10 characters
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "Input matrix line (%d)'s width is more than 10 characters.\n", height);
      return EXIT_FAILURE;
    }
    
    // If line has less than 10 characters
    int isNewLine = 0;
    for (int n=0; n<LINE_LENGTH; n++) {
      if (line[n] == '\n') {
	isNewLine = n;
      }
    }
    if (isNewLine < MATRIX_SIZE) {
      fprintf(stderr, "Input matrix line (%d)'s width is %d, which is less than 10 characters.\n", height, isNewLine);
      return EXIT_FAILURE;
    }
    
    for (int i=0; i<MATRIX_SIZE; i++) {
      matrix[height][i] = line[i];
    }

    height++;
  }
  // if matrix has less than 10 rows
  if(height < MATRIX_SIZE) {
    fprintf(stderr, "Input matrix height is %d (which is too small), but should be 10.", height-1);
    return EXIT_FAILURE;
  }

  // if matrix has more than 10 rows
  if (height > MATRIX_SIZE) {
    fprintf(stderr, "Input matrix height is %d (which is too big), but should be 10.\n", height-1);
    return EXIT_FAILURE;
  }
  // if the file does not close
  if (fclose(f) != 0) {
    perror("Failed to close the file!");
    return EXIT_FAILURE;
  }

  // rotate the matrix 90 degrees clockwise and print it to stdout
  rotate(matrix);

  return EXIT_SUCCESS;
}
