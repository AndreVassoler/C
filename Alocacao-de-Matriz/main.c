#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int **mat, i,j;

  mat = malloc(4 * sizeof(int*));

  for(i = 0; i < 4; i++){
    mat[i] = malloc(3 * sizeof(int));
  }
}