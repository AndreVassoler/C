#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura para representar um nó da lista de adjacências
struct Node {
    int data;
    struct Node* next;
};

// Estrutura para representar um vértice do grafo
struct Vertex {
    int data;
    bool visited;
    struct Node* adjList;
};

// Estrutura para representar o grafo
struct Graph {
    int numVertices;
    struct Vertex* vertices;
};

// Função para criar um novo nó da lista de adjacências
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com 'numVertices' vértices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->vertices = (struct Vertex*)malloc(numVertices * sizeof(struct Vertex));

    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i].data = i;
        graph->vertices[i].visited = false;
        graph->vertices[i].adjList = NULL;
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona uma aresta do src ao dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->vertices[src].adjList;
    graph->vertices[src].adjList = newNode;
}

// Função para realizar a busca em largura
void BFS(struct Graph* graph, int startVertex) {
    // Cria uma fila para a busca em largura
    int queue[graph->numVertices];
    int front = 0, rear = 0;
    queue[rear++] = startVertex;
    graph->vertices[startVertex].visited = true;

    printf("Resultado da Busca em Largura (BFS):\n");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->vertices[currentVertex].adjList;
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!graph->vertices[adjVertex].visited) {
                queue[rear++] = adjVertex;
                graph->vertices[adjVertex].visited = true;
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    printf("Lista de Adjacências:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vértice %d: ", i);
        struct Node* current = graph->vertices[i].adjList;
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
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

    struct Graph* graph = createGraph(numVertices);

    int choice, src, dest;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar aresta\n");
        printf("2. Realizar Busca em Largura (BFS)\n");
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
                if (!isDirected) {
                    addEdge(graph, dest, src);
                }
                break;
            case 2:
                printf("Digite o vértice de início da Busca em Largura (BFS): ");
                scanf("%d", &src);
                printf("Resultado da Busca em Largura (BFS) a partir do vértice %d:\n", src);
                BFS(graph, src);
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