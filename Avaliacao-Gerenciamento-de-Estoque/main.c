#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do produto
typedef struct {
  char nome[50];
  float preco;
  int quantidade;
} Produto;

// Definição da estrutura do nó da lista ligada
typedef struct No {
  Produto produto;
  struct No *prox;
} No;

// Função para criar um novo nó da lista
No *criar_no(Produto produto) {
  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->produto = produto;
  novo_no->prox = NULL;
  return novo_no;
}

// Função para adicionar um produto ao estoque
void adicionar_produto(No **estoque) {
  Produto produto;
  printf("Digite o nome do produto: ");
  scanf("%s", produto.nome);
  printf("Digite o preço do produto: ");
  scanf("%f", &produto.preco);
  printf("Digite a quantidade do produto: ");
  scanf("%d", &produto.quantidade);

  No *novo_no = criar_no(produto);
  novo_no->prox = *estoque;
  *estoque = novo_no;
  printf("Produto adicionado ao estoque.\n");
}

// Função para remover um produto do estoque
void remover_produto(No **estoque, char *nome_produto, int quantidade) {
  No *atual = *estoque;
  No *anterior = NULL;

  while (atual != NULL) {
    if (strcmp(atual->produto.nome, nome_produto) == 0) {
      if (atual->produto.quantidade >= quantidade) {
        atual->produto.quantidade -= quantidade;
        if (atual->produto.quantidade == 0) {
          if (anterior == NULL) {
            *estoque = atual->prox;
          } else {
            anterior->prox = atual->prox;
          }
          free(atual);
        }
        printf("Produto removido do estoque.\n");
        return;
      } else {
        printf("Quantidade insuficiente no estoque.\n");
        return;
      }
    }
    anterior = atual;
    atual = atual->prox;
  }
  printf("Produto não encontrado.\n");
}

// Função para exibir informações sobre um produto específico
void obter_informacoes_produto(No *estoque, char *nome_produto) {
  No *atual = estoque;
  while (atual != NULL) {
    if (strcmp(atual->produto.nome, nome_produto) == 0) {
      printf("Nome: %s\nPreço: R$%.2f\nQuantidade: %d unidades\n",
             atual->produto.nome, atual->produto.preco,
             atual->produto.quantidade);
      return;
    }
    atual = atual->prox;
  }
  printf("Produto não encontrado.\n");
}

// Função principal
int main() {
  No *estoque = NULL;
  int opcao;
  char nome_produto[50];
  int quantidade;

  do {
    printf("\n1. Adicionar produto ao estoque\n");
    printf("2. Remover produto do estoque\n");
    printf("3. Obter informações de um produto\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      adicionar_produto(&estoque);
      break;
    case 2:
      printf("Digite o nome do produto a ser removido: ");
      scanf("%s", nome_produto);
      printf("Digite a quantidade a ser removida: ");
      scanf("%d", &quantidade);
      remover_produto(&estoque, nome_produto, quantidade);
      break;
    case 3:
      printf("Digite o nome do produto: ");
      scanf("%s", nome_produto);
      obter_informacoes_produto(estoque, nome_produto);
      break;
    case 4:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida.\n");
    }
  } while (opcao != 4);

  return 0;
}
