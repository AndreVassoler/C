#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarFila(Fila *fila) {
    fila->inicio = fila->fim = NULL;
}

void adicionarTarefaFila(Fila *fila, const char *descricao, int prioridade) {
    Tarefa *novaTarefa = (Tarefa *)malloc(sizeof(Tarefa));
    if (novaTarefa == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tarefa\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novaTarefa->descricao, descricao);
    novaTarefa->prioridade = prioridade;
    novaTarefa->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = fila->fim = novaTarefa;
    } else {
        fila->fim->proximo = novaTarefa;
        fila->fim = novaTarefa;
    }
}

Tarefa *removerTarefaFila(Fila *fila) {
    if (fila->inicio == NULL) {
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);
    }

    Tarefa *tarefaRemovida = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return tarefaRemovida;
}

void imprimirFila(Fila *fila) {
    Tarefa *atual = fila->inicio;
    while (atual != NULL) {
        printf("Descrição: %s, Prioridade: %d\n", atual->descricao, atual->prioridade);
        atual = atual->proximo;
    }
}

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void adicionarTarefaPilha(Pilha *pilha, const char *descricao, int prioridade) {
    Tarefa *novaTarefa = (Tarefa *)malloc(sizeof(Tarefa));
    if (novaTarefa == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tarefa\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novaTarefa->descricao, descricao);
    novaTarefa->prioridade = prioridade;
    novaTarefa->proximo = pilha->topo;
    pilha->topo = novaTarefa;
}

Tarefa *removerTarefaPilha(Pilha *pilha) {
    if (pilha->topo == NULL) {
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE);
    }

    Tarefa *tarefaRemovida = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    return tarefaRemovida;
}

void imprimirPilha(Pilha *pilha) {
    Tarefa *atual = pilha->topo;
    while (atual != NULL) {
        printf("Descrição: %s, Prioridade: %d\n", atual->descricao, atual->prioridade);
        atual = atual->proximo;
    }
}

void liberarMemoria(Tarefa *tarefa) {
    free(tarefa);
}
