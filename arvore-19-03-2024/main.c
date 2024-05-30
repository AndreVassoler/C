#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *esquerdo, *direito;
  int altura;
} No;

No* novoNo(int x){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = x;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    novo->altura = 0;
  }else
    printf("\nErro ao alocar memoria.\n");
  return novo;
}

int maior(int a, int b){
  return (a > b)? a: b;
}

int alturaNo(No *no) {
  if(no == NULL)
    return -1;
  else
    return no->altura;
}

int fatorBalanceamento(No *no){
  if(no)
    return (alturaNo(no->esquerdo) - alturaNo(no->direito));
  else
    return 0;
}

No* rotacaoEsquerda(No *r){
  No *y, *f;

  y = r->direito;
  f = y->esquerdo;

  y->esquerdo = r;
  r->direito = f;

  r->altura = maior(alturaNo(r->esquerdo), alturaNo(r->direito)) + 1;
  y->altura = maior(alturaNo(y->esquerdo), alturaNo(y->direito)) + 1;

  return y;
}

No* rotacaoDireita(No *r){
  No *y, *f;

  y = r->esquerdo;
  f = y->direito;

  y->direito = r;
  r->esquerdo = f;

  r->altura = maior(aluraNo(r->esquerdo), alturaNo(r->direito)) + 1;
  y->altura = maior(alturaNo(y->esquerdo), alturaNo(y->esquerdo)) + 1;

  return y;
}

No* rotacaoEsquerdaDireita(No *r){
  r->esquerdo = rotacaoEsquerda(r->esquerdo);
  return rotacaoDireita(r);
}

No* rotacaoDireitaEsquerda(No *r) {
  r->direito = rotacaoDireita(r->direito);
  return rotacaoEsquerda(r);
}

No* balancear(No *raiz){
  int fb = fatorBalanceamento(raiz);

  if(fb < -1 && fatorBalanceamento(raiz->direito) <= 0)
    raiz = rotacaoEsquerda(raiz);

  else if(fb > 1 && fatorBalanceamento(raiz->esquerda) >= 0)
    raiz = rotacaoDireita(raiz);

  else if(fb > 1 && fatorBalanceamento(raiz->direita) < 0)
    raiz = rotacaoDireita(raiz);
}