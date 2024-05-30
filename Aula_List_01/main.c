#include <stdio.h>

int main(void) {
  int opacao, valor, anterior;
  No *no, *lista = NULL;

  do{
    printf("\n\t0 - Sair\n\t1 - Inserir Inicio\n\t2 - Inserir Fim\n\t3 - Inserir Meio\n\t4 - Remover\n\t5 - Imprimir\n\t6 - Buscar\n\t7 - Ultimo\n");
    scanf("%d", &opacao);

    switch(opacao){
      case 1:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserir_inicio(&lista, valor);
        break;
      case 2:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserir_fim(&lista, valor);
        break;
      case 3:
        printf("Digite um valor: ");
        sacanf("&d", &valor);
        inseriro_meio(&lista, valor, &anterior);;
        break;
      case 4:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_ordenado(&lista, valor);
        break;
      case 5:
        printf("Remover valor: ");
        scanf("%d", &valor);
        no = remover(&lista, valor);
        if(no){
          printf("Elemento: %d", no->valor);
          free(no);
        }else







      
        
  }
  
}