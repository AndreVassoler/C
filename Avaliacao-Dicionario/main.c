#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura do nó da árvore binária de busca
typedef struct Node {
    char palavra[50];
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Função para criar um novo nó da árvore
Node* criar_no(char* palavra) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    strcpy(novo_no->palavra, palavra);
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

// Função para inserir uma palavra na árvore
Node* inserir_palavra(Node* raiz, char* palavra) {
    if (raiz == NULL) {
        return criar_no(palavra);
    }

    if (strcasecmp(palavra, raiz->palavra) < 0) {
        raiz->esquerda = inserir_palavra(raiz->esquerda, palavra);
    } else if (strcasecmp(palavra, raiz->palavra) > 0) {
        raiz->direita = inserir_palavra(raiz->direita, palavra);
    }

    return raiz;
}

// Função para buscar uma palavra na árvore
int buscar_palavra(Node* raiz, char* palavra) {
    if (raiz == NULL) {
        return 0;
    }

    if (strcasecmp(palavra, raiz->palavra) == 0) {
        return 1;
    } else if (strcasecmp(palavra, raiz->palavra) < 0) {
        return buscar_palavra(raiz->esquerda, palavra);
    } else {
        return buscar_palavra(raiz->direita, palavra);
    }
}

// Função para liberar a memória da árvore
void liberar_arvore(Node* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}

// Função principal
int main() {
    Node* raiz = NULL;
    char palavra[50];
    char opcao;

    FILE* arquivo;

    // Abrir o arquivo para leitura
    arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Ler palavras do arquivo e inserir na árvore
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        raiz = inserir_palavra(raiz, palavra);
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Loop principal
    do {
        // Verificando se uma palavra está presente no dicionário
        printf("Digite uma palavra para verificar se está presente no dicionário: ");
        scanf("%s", palavra);
        if (buscar_palavra(raiz, palavra)) {
            printf("A palavra \"%s\" está presente no dicionário.\n", palavra);
        } else {
            printf("A palavra \"%s\" não está presente no dicionário.\n", palavra);
        }

        // Perguntar ao usuário se deseja continuar
        printf("Deseja perguntar novamente? (S/N): ");
        scanf(" %c", &opcao); // Espaço antes de %c para consumir a quebra de linha anterior

        // Converter a opção para maiúscula para tratamento consistente
        opcao = toupper(opcao);

    } while (opcao == 'S');

    // Liberando a memória da árvore
    liberar_arvore(raiz);

    return 0;
}
