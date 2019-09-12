#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int searchMaxIdx (int arr[], int size) {
  int maxIdx = 0;

  for (int i = 1; i < size; i++) {
    if (arr[i] > arr[maxIdx]) {
      maxIdx = i;
    }
  }

  return maxIdx;
}

int getKey(FILE *file) {
  int frequency[26] = {0};
  int character;
  int maxIdx;

  while ((character = fgetc(file)) != EOF ) {
      if (isalpha(character)) {
	frequency[tolower(character) - 'a']++;
      }
    }

    maxIdx = searchMaxIdx (frequency, 26);
    return (maxIdx + 22) % 26;
}

int main(int argc, char *argv[]) {
  FILE *file;
  int key;

  if (argc !=2) {
    fprintf(stderr, "Usage %s file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  file = fopen(argv[1], "r");

  if (file == NULL) {
    fprintf(stderr, "Error openning the file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  key = getKey(file);
  printf("%d\n", key);

  fclose(file);
  return 0;
}
