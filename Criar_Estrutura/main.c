#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 15

typedef struct no{
  int chave;
  struct no *proximo;
}No;

typedef struct{
  No *inicio;
  int tam;
}Lista;

void inicializarLista(Lista *l){
  l->inicio = NULL;
  l->tam = 0;
}

void inserir_lista(Lista *l, int valor){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->chave = valor;
    novo->proximo = l->inicio;
    l->inicio = novo;
    l->tam++;
  }else
    printf("Erro ao alocar memoria!\n");
}

int buscar_lista(Lista *l, int valor){
  No *aux = l->inicio;
  while(aux && aux->chave != valor)
    aux = aux->proximo;
  if(aux)
    return aux->chave;
  return 0;
}

void imprimir_lista(Lista *l){
  No *aux = l->inicio;
  printf("Tam: %d " , l->tam);
  while(aux)
    printf("%d ", aux->chave);
    aux = aux->proximo;
}

void inicializarTabela(Lista t[]){
  int i;
  for(i = 0; i < TAM; i++)
    inicializarLista(&t[i]);
}