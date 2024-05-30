#include "lista.h"

int main() {
    Fila filaTarefas;
    Pilha pilhaTarefasAltaPrioridade;

    inicializarFila(&filaTarefas);
    inicializarPilha(&pilhaTarefasAltaPrioridade);

    adicionarTarefaFila(&filaTarefas, "Desenvolver recurso 1", 2);
    adicionarTarefaFila(&filaTarefas, "Corrigir bug 1", 1);
    adicionarTarefaPilha(&pilhaTarefasAltaPrioridade, "Tratar tarefa crítica 1", 5);
    adicionarTarefaFila(&filaTarefas, "Documentar código", 3);
    adicionarTarefaPilha(&pilhaTarefasAltaPrioridade, "Tratar tarefa crítica 2", 5);

    printf("Tarefas na fila:\n");
    imprimirFila(&filaTarefas);

    printf("\nTarefas na pilha de alta prioridade:\n");
    imprimirPilha(&pilhaTarefasAltaPrioridade);

    Tarefa *tarefaRemovidaFila = removerTarefaFila(&filaTarefas);
    Tarefa *tarefaRemovidaPilha = removerTarefaPilha(&pilhaTarefasAltaPrioridade);

    printf("\nTarefa removida da fila: %s\n", tarefaRemovidaFila->descricao);
    printf("Tarefa removida da pilha: %s\n", tarefaRemovidaPilha->descricao);

    liberarMemoria(tarefaRemovidaFila);
    liberarMemoria(tarefaRemovidaPilha);

    return 0;
}
