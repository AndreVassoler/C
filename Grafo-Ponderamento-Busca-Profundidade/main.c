#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Estrutura para representar um grafo ponderado
struct Graph {
    int numVertices;
    int graphMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Função para criar um novo grafo
struct Graph createGraph(int numVertices) {
    struct Graph graph;
    graph.numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph.graphMatrix[i][j] = 0; // Inicializa com 0 para indicar ausência de aresta
        }
    }
    return graph;
}

// Função para adicionar uma aresta ponderada
void addEdge(struct Graph* graph, int src, int dest, int weight, bool isDirected) {
    graph->graphMatrix[src][dest] = weight;
    if (!isDirected) {
        graph->graphMatrix[dest][src] = weight; // Para um grafo não direcionado, a aresta é bidirecional
    }
}

// Função para realizar a busca em profundidade (DFS)
void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->graphMatrix[vertex][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Função para iniciar a DFS a partir de um vértice específico
void startDFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // Inicializa todos os vértices como não visitados
    printf("Busca em Profundidade a partir do vértice %d: ", startVertex);
    DFS(graph, startVertex, visited);
    printf("\n");
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    printf("Matriz de Adjacência do Grafo:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d\t", graph->graphMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices, isDirected;
    printf("Digite o número de vértices: ");
    scanf("%d", &numVertices);
    printf("O grafo é direcionado? (1 para sim, 0 para não): ");
    scanf("%d", &isDirected);

    struct Graph graph = createGraph(numVertices);

    int numEdges, src, dest, weight;
    printf("Digite o número de arestas: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Digite a origem, destino e peso da aresta %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight, isDirected);
    }

    printGraph(&graph);

    int startVertex;
    printf("Digite o vértice de início da busca em profundidade: ");
    scanf("%d", &startVertex);
    startDFS(&graph, startVertex);

    return 0;
}
