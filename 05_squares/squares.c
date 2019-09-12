#include <stdio.h>
#include <stdlib.h>

int max(int f1, int f2) {
  // compare f1 to f2
  if (f1 > f2) {
    // if f1 is larger than f2, then f1 is your answer
    return f1;
  }
  else {
    // otherwise, f2 is your answer
    return f2;
  }
}



void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int xos2 = (x_offset + size2);
  int w = max (size1, xos2);
  //compute the max of size1 and (y_offset + size2).  Call this h
  int yos2 = (y_offset + size2);
  int h = max (size1, yos2);
  //count from 0 to h. Call the number you count with y
  for (int y=0; y<h; y++){
    //count from 0 to w. Call the number you count with x
    for (int x=0; x<w; x++){
      //check if  EITHER
      int isXBetween = (x_offset <= x) && (x < xos2);
      int isYEqual = (y == y_offset) || (y == (y_offset + size2 - 1));
      int isYBetween = (y_offset <= y) && (y < yos2);
      int isXEqual = (x == x_offset) || (x == (x_offset + size2 - 1));

      if ((isXBetween && isYEqual) || (isYBetween && isXEqual)){
	//    ((x is between x_offset  and x_offset +size2) AND
	//     y is equal to either y_offset OR y_offset + size2 - 1 )
	//  OR
	//    ((y is between y_offset and y_offset + size2) AND
	//     x is equal to either x_offset OR x_offset + size2 -1)
	// if so, print a *
      
	printf("*");}
      else {
	//if not,
	// check if EITHER
      
	int isXless = (x < size1) ;
	int isX = (y == 0) || (y == (size1 - 1));
	int isYless = (y < size1) ;
	int isY = (x == 0) || (x == (size1 - 1));
      
	if ((isXless && isX) || (isYless && isY)) {
	  //    x is less than size1 AND (y is either 0 or size1-1)
	  // OR
	  //    y is less than size1 AND (x is either 0 or size1-1)
	  //if so, print a #
      
	  printf("#");
      
	}
	//else print a space
	else {
          printf(" ");
	}
      }
    }
    //when you finish counting x from 0 to w,
    printf("\n"); //print a newline
  }
}
