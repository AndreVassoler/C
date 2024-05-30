#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calcularPopularidade(No* livro) {
    if (livro->avaliacao + livro->alugado == 0) {
        return 0.0;
    }
    return (float)livro->alugado / (livro->avaliacao + livro->alugado);
}

void inserirLivro(No** head, char titulo[], char autor[], int avaliacao, int alugado) {
    No* novoLivro = (No*)malloc(sizeof(No));
    strcpy(novoLivro->titulo, titulo);
    strcpy(novoLivro->autor, autor);
    novoLivro->avaliacao = avaliacao;
    novoLivro->alugado = alugado;

    if (*head == NULL || calcularPopularidade(novoLivro) > calcularPopularidade(*head)) {
        novoLivro->proximo = *head;
        *head = novoLivro;
    } else {
        No* current = *head;
        while (current->proximo != NULL && calcularPopularidade(novoLivro) <= calcularPopularidade(current->proximo)) {
            current = current->proximo;
        }
        novoLivro->proximo = current->proximo;
        current->proximo = novoLivro;
    }
}

void removeLivro(No** head, char titulo[]) {
    if (*head == NULL) {
        return; 
    }

    if (strcmp((*head)->titulo, titulo) == 0) {
        No* temp = *head;
        *head = (*head)->proximo;
        free(temp);
        return;
    }

    No* current = *head;
    while (current->proximo != NULL && strcmp(current->proximo->titulo, titulo) != 0) {
        current = current->proximo;
    }

    if (current->proximo != NULL) {
        No* temp = current->proximo;
        current->proximo = temp->proximo;
        free(temp);
    }
}

No* getMaisPopular(No* head) {
    if (head == NULL) {
        return NULL;
    }
    return head;
}

void mostraLivro(No* head) {
    No* current = head;
    while (current != NULL) {
        printf("Título: %s\n", current->titulo);
        printf("Autor: %s\n", current->autor);
        printf("Disponíveis: %d\n", current->avaliacao);
        printf("Emprestados: %d\n", current->alugado);
        printf("Popularidade: %.2f\n\n", calcularPopularidade(current));
        current = current->proximo;
    }
}

void freeList(No* head) {
    No* current = head;
    while (current != NULL) {
        No* temp = current;
        current = current->proximo;
        free(temp);
    }
}
