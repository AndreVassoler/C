#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um grafo
struct Graph {
    int numVertices;
    int** adjMatrix;
    int isDirected;
};

// Função para criar um grafo com 'numVertices' vértices
struct Graph* createGraph(int numVertices, int isDirected) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->isDirected = isDirected;

    // Aloca espaço para a matriz de adjacência e inicializa com zeros
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona uma aresta do src para o dest
    graph->adjMatrix[src][dest] = 1;

    if (!graph->isDirected) {
        // Se não for um grafo dirigido, adicione também uma aresta do dest ao src
        graph->adjMatrix[dest][src] = 1;
    }
}

// Função para remover uma aresta do grafo
void removeEdge(struct Graph* graph, int src, int dest) {
    // Remove a aresta do src para o dest
    graph->adjMatrix[src][dest] = 0;

    if (!graph->isDirected) {
        // Se não for um grafo dirigido, remova também a aresta do dest ao src
        graph->adjMatrix[dest][src] = 0;
    }
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices, isDirected;
    printf("Escolha o tipo de grafo:\n");
    printf("0. Grafo não dirigido\n");
    printf("1. Grafo dirigido\n");
    printf("Digite a opção (0 ou 1): ");
    scanf("%d", &isDirected);

    printf("Digite o número de vértices do grafo: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices, isDirected);

    int choice, src, dest;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar conexão\n");
        printf("2. Remover conexão\n");
        printf("3. Imprimir grafo\n");
        printf("4. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o vértice de origem: ");
                scanf("%d", &src);
                printf("Digite o vértice de destino: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                printf("Conexão adicionada.\n");
                break;
            case 2:
                printf("Digite o vértice de origem: ");
                scanf("%d", &src);
                printf("Digite o vértice de destino: ");
                scanf("%d", &dest);
                removeEdge(graph, src, dest);
                printf("Conexão removida.\n");
                break;
            case 3:
                printGraph(graph);
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}