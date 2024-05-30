#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int **mat, i, j;

  mat = malloc(4 * sizeof(int*));

  for (i = 0; i < 4; i++){
    mat[i] = malloc(3 * sizeof(int));
  }

  srand(time(NULL));

  for (i = 0; i < 4; i++){
    for(j = 0; j < 3; j++){
      mat[i][j] = rand() % 100;
    }
  }

  for (i = 0; i < 4; i++){
    for (j = 0; j < 3; j++){
      printf("| %d-%p-%p| ", mat[i][j]), &mat[i][j], mat[i][j];
    }
    printf("\n");
  }

    printf("\n");
    printf("%p %p", &mat, mat);
    printf("\n");
    printf("\n");

  for (i = 0; i < 4; i++){
    printf("| %p %p |", &mat[i], mat[i]);
      printf("\n");
  }
  
  //free(mat);
  
}