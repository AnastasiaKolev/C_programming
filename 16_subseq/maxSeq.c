#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  size_t null_num = 0;
  if (n == 0) {
    return null_num;
  }
    
  size_t l = 1;
  size_t maxl = 1;
  for (size_t i = 1; i < n; i++){
    if (*(array + i - 1) < *(array + i)){
      l++;
    }
    else{
      if(maxl < l){
	maxl = l;
      }
      l = 1;
    }
  }
  if(maxl < l){
    maxl = l;
  }
  
  return maxl;
}
