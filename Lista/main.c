#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia, mes, ano;
}Data;

typedef struct {
  char nome[30];
  Data data;
}Pessoa;

typedef struct no{
  Pessoa p;
  struct no *proximo;
}No;

Pessoa ler_pessoa() {
  Pessoa p;
  printf("\nNome: ");
  scanf("%29[^\n]", p.nome);
  printf("\nData de nascimento: ");
  scanf("%d%d%d", &p.data.dia, &p.data.mes, &p.data.ano);
  return p;
}

void imprimir(Pessoa p){
  printf("\nNome: %s\nData: %2d/%2d/%4d", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

No* empilhar(No *topo){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo -> p = ler_pessoa();
    novo -> proximo = topo;
    return novo;
  }
  else{
    printf("\nErro ao alocar memória.\n");
  }
  return NULL;
}

int main(void) {
  
}