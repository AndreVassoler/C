#include <stdio.h>
#include <stdlib.h>

typedef struct no{
Pessoa p;
struct no *proximo;
}No;

No* empilhar(No *topo){
No *novo = malloc(sizeof(No));

if(novo){
novo->p = ler_pessoa();
novo->proximo = p->topo;
p->topo = novo;
p->tam++;
}else
printf("\n Erro ao alocar memoria.\n");
}

No* desempilhar(No **pilha){
  No *remover = NULL;
  if(*pilha){
    remover = *pilha;
    *pilha = remover->proximo
  }else{
    printf("\nPilha vazia.\n");

  }
  return remover;
}

void imprimir(No *pilha){
  while(pilha){
    printf("%d\n", pilha->valor);
    pilha = pilha->proximo;
  }
  printf("\n");
}

int fatorial(int num){
  No *remover, *pilha = NULL;

  while(num > 1){
    pilha = empilhar(pilha, num);
    num--;
  }

  imprimir(pilha);

  while(pilha){
    remover = desempilhar(&pilha);
    num = num * remover->valor;
    free(remover);
  }
  return num;
}

int main(void){
  int n;

  printf("\nDigite um valor maior que zero: ");
  scanf("%d", &n);

  printf("Fatorial de %d: %d",n, fatorial(n));  
}
