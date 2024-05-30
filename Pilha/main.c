#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char titulo[50];
  char descricao[100];
  int prioridade;
}Tarefa;

typedef struct No{
  Tarefa tarefa;
  struct No *proximo;
}No;

typedef struct{
  No *topo;
}Pilha;

Pilha * criarPilha(){
  Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
  pilha->topo = NULL;
  return pilha;
}

void push(Pilha *pilha, Tarefa tarefa){
  No *novo = (No*)malloc(sizeof(No));
  novo->tarefa = tarefa;
  novo->proximo = pilha->topo;
  pilha->topo = novo;
}

Tarefa pop(Pilha *pilha){
  if(pilha->topo == NULL){
    Tarefa vazia = {"","",0};
    return vazia;
  }

  No *aux = pilha->topo;
  pilha->topo = pilha->topo->proximo;
  Tarefa remove = aux->tarefa;
  free(aux);
  return remove;
}

int vazia(Pilha *pilha){
  return pilha->topo == NULL;
}

int main(void) {
  Pilha *pilha = criarPilha();

  Tarefa tarefa1 = {"Implementar autentição", "Implementar o sistema de autenticação de usuários.", 3};
  Tarefa tarefa2 = {"Corrigir bug na página inicial", "Resolver o bug que causa travamento na página inicial.", 1};
  Tarefa tarefa3 = {"Atualizar documentação", "Atualizar a documentação do projeto.", 2};

  push(pilha, tarefa1);
  push(pilha, tarefa2);
  push(pilha, tarefa3);

  printf("Tarefa na pilha:\n");
  while (!vazia(pilha)){
    Tarefa remove = pop(pilha);
    printf("Título: %s\nDescrição: %s\nPrioridade %d\n\n", remove.titulo, remove.descricao, remove.prioridade);
  }
  
  
  return 0;
}