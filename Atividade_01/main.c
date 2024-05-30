// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
 
//   char nomes[3][10];
//   float notas[3];

//   int i;

//   for(i = 0; i < 3; i++){
//     printf("Digite nome e a nota do %dº Aluno: ", i+1);
//     scanf("%s%f", &nomes[i], &notas[i]);
//   }

//   printf("\nNome\t\tNota\n");
//   for (i = 0; i < 3; i++){
//     printf("%s\t\t%.2f\n", nomes[i], notas[i]);
//   }

// }
  //-----------Utilizando Ponteiro--------------
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int x, y;

  char ** alunos;
  float * notas;
  
  alunos = malloc(3 * sizeof(char*));
  for (x=0; x<=2; x++)
    alunos[x] = malloc(10 * sizeof(char));
  notas = malloc(3 * sizeof(float));
    
  for (x=0; x<=2; x++){
    printf("Digite o nome e nota do aluno: ");
    scanf("%s%f", &alunos[x][0], &notas[x]);
  }

  printf("\nNome\t\t\tNota\n");
  
  for (int x=0; x<=2; x++){
    printf("Nome: %s\t\t\t%.2f\n", alunos[x], notas[x]);
  }
  
}