#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para um contato
typedef struct Contato {
    char nome[50];
    char telefone[15];
    struct Contato *esq;
    struct Contato *dir;
} Contato;

// Função para criar um novo contato
Contato* criar_contato(char nome[], char telefone[]) {
    Contato *novo_contato = (Contato*)malloc(sizeof(Contato));
    strcpy(novo_contato->nome, nome);
    strcpy(novo_contato->telefone, telefone);
    novo_contato->esq = NULL;
    novo_contato->dir = NULL;
    return novo_contato;
}

// Função para inserir um contato na árvore binária de busca
Contato* inserir_contato_arvore(Contato *raiz, char nome[], char telefone[]) {
    if (raiz == NULL) {
        return criar_contato(nome, telefone);
    }

    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esq = inserir_contato_arvore(raiz->esq, nome, telefone);
    } else if (strcmp(nome, raiz->nome) > 0) {
        raiz->dir = inserir_contato_arvore(raiz->dir, nome, telefone);
    }

    return raiz;
}

// Função para exibir contatos em ordem alfabética
void exibir_contatos_em_ordem(Contato *raiz) {
    if (raiz != NULL) {
        exibir_contatos_em_ordem(raiz->esq);
        printf("Nome: %s, Telefone: %s\n", raiz->nome, raiz->telefone);
        exibir_contatos_em_ordem(raiz->dir);
    }
}

// Função para liberar a memória alocada para a árvore
void liberar_arvore(Contato *raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

// Definindo a estrutura para a lista telefônica usando lista encadeada
typedef struct {
    Contato *inicio;
} ListaEncadeada;

// Função para inicializar a lista encadeada
void inicializar_lista_encadeada(ListaEncadeada *lista) {
    lista->inicio = NULL;
}

// Função para adicionar um contato à lista encadeada
void adicionar_contato_lista_encadeada(ListaEncadeada *lista, char nome[], char telefone[]) {
    Contato *novo_contato = (Contato*)malloc(sizeof(Contato));
    strcpy(novo_contato->nome, nome);
    strcpy(novo_contato->telefone, telefone);
    novo_contato->esq = NULL;
    novo_contato->dir = NULL;

    if (lista->inicio == NULL || strcmp(nome, lista->inicio->nome) < 0) {
        novo_contato->dir = lista->inicio;
        lista->inicio = novo_contato;
    } else {
        Contato *atual = lista->inicio;
        while (atual->dir != NULL && strcmp(nome, atual->dir->nome) > 0) {
            atual = atual->dir;
        }
        novo_contato->dir = atual->dir;
        atual->dir = novo_contato;
    }
}

// Função para exibir todos os contatos da lista encadeada
void exibir_contatos_lista_encadeada(ListaEncadeada *lista) {
    Contato *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Telefone: %s\n", atual->nome, atual->telefone);
        atual = atual->dir;
    }
}

int main() {
    Contato *raiz_arvore = NULL;
    ListaEncadeada lista_encadeada;
    inicializar_lista_encadeada(&lista_encadeada);

    char nome[50];
    char telefone[15];
    char opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Exibir contatos em ordem de inserção (lista encadeada)\n");
        printf("3. Exibir contatos em ordem alfabética (árvore binária)\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        switch(opcao) {
            case '1':
                printf("Digite o nome do contato: ");
                scanf("%s", nome);
                printf("Digite o telefone do contato: ");
                scanf("%s", telefone);
                raiz_arvore = inserir_contato_arvore(raiz_arvore, nome, telefone);
                adicionar_contato_lista_encadeada(&lista_encadeada, nome, telefone);
                break;
            case '2':
                printf("\nContatos em ordem de inserção (lista encadeada):\n");
                exibir_contatos_lista_encadeada(&lista_encadeada);
                break;
            case '3':
                printf("\nContatos em ordem alfabética (árvore binária):\n");
                exibir_contatos_em_ordem(raiz_arvore);
                break;
            case '4':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
        }
    } while(opcao != '4');

    liberar_arvore(raiz_arvore);

    return 0;
}
