#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

void inserir(No **fila, int num) {
  No *aux, *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = NULL;
    if(*fila == NULL){
      *fila = novo;
    }else{
      aux = *fila;
      while(aux->proximo){
        aux = aux->proximo;
      }
      aux->proximo = novo;
    }
  }else{
    printf("\nErro ao alocar memória.\n");
  }

  No* remover(No **fila){
    No *remove = NULL;

    if(*fila) {
      remove = *fila;
      *fila = remove->proximo;
    }else{
      printf("\nFila vazi.\n");
    }
    return remove;

    void imprimir(No *fila) {
      while(fila) {
        printf("%d ", fila->valor);
        fila = fila->proximo;
      }
      printf("\n");
    }
  }
  
}




