#ifndef fila
#define fila

typedef struct no{
  int valor;
  struct no *proximo;
}No;

void inserir(No **fila, int num);

No remover(No **fila);

void imprimir(No *fila);

#endif