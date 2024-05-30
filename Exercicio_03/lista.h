#ifndef lista_h
#define lista_h

typedef struct Tarefa {
    char descricao[100];
    int prioridade;
    struct Tarefa *proximo;
} Tarefa;

typedef struct Fila {
    Tarefa *inicio;
    Tarefa *fim;
} Fila;

typedef struct Pilha {
    Tarefa *topo;
} Pilha;

void inicializarFila(Fila *fila);
void adicionarTarefaFila(Fila *fila, const char *descricao, int prioridade);
Tarefa *removerTarefaFila(Fila *fila);
void imprimirFila(Fila *fila);

void inicializarPilha(Pilha *pilha);
void adicionarTarefaPilha(Pilha *pilha, const char *descricao, int prioridade);
Tarefa *removerTarefaPilha(Pilha *pilha);
void imprimirPilha(Pilha *pilha);

void liberarMemoria(Tarefa *tarefa);

#endif
