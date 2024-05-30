#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 256

typedef struct no{
  unsigned char caractere;
  int frequencia;
  struct no *esq, *dir, *proximo;
}No;

typedef struct{
  No *inicio;
  int tam;
}Lista;

void criar_lista(Lista *lista){
  lista->inicio = NULL;
  lista->tam = 0;
}

void inicia_tabela(unsigned int tab[]){
  int i;
  for(i = 0; i < TAM; i++)
    tab[i] = 0;
}

void preenche_tab_freq(unsigned char texto[], unsigned int tab[]){
  int i = 0;

  while(texto[i] != '\0'){
    tab[texto[i]]++;
    i++;
  }
}

void imprime_tab_freq(unsigned int tab[]){
  int i;

  printf("\tTabela de frequência:\n");
  for(i = 0; i < TAM; i++){
    if(tab[i] > 0)
      printf("\t%3d = %u = %c\n", i, tab[i], i);
  }
}

void inserir_ordenado(Lista *lista, No *no){
  No *aux;

  if(lista->inicio == NULL){
    lista->inicio = no;
  }else if(no->frequencia < lista->inicio->frequencia){
    no->proximo = lista->inicio;
    lista->inicio = no;
  }else{
    aux = lista->inicio;
    while(aux->proximo && aux->proximo->frequencia <= no->frequencia)
      aux = aux->proximo;
    no->proximo = aux->proximo;
    aux->proximo = no;
  }
  lista->tam++;  
}

void preencher_lista(unsigned int tab[], Lista *lista){
  int i;
  No *novo;
  for(i = 0; i < TAM; i++){
    if(tab[i] > 0){
      novo = malloc(sizeof(No));
      if(novo){
        novo->caractere = i;
        novo->frequencia = tab[i];
        novo->dir = NULL;
        novo->esq = NULL;
        novo->proximo = NULL;
        inserir_ordenado(lista, novo);
      }else{
        printf("\nErro ao alocar memória em preencher_lista!\n");
        break;
      }
    }
  }
}

int main(void){
  unsigned char texto[] = "Vamos aprender a programar";
  unsigned int tab_freq[TAM]; 

  setlocale(LC_ALL, "Portuguese");

  inicia_tabela(tab_freq);
  preenche_tab_freq(texto, tab_freq);
  imprime_tab_freq(tab_freq);
}