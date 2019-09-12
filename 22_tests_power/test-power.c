#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

void test(unsigned x, unsigned y, unsigned  correct_ans){
  if (power (x, y)  != correct_ans){
    printf("broken\n");
    exit(EXIT_FAILURE);
  }
}

int main(void) {

  test(2, 2, 4);
 
  test(1, 0, 1);

  test(0, 0, 1);
  
  test(234, 4, 2998219536);

  
  return EXIT_SUCCESS;
}
