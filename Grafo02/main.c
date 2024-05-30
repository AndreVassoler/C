#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó de lista de adjacências
struct Node {
    int data;
    struct Node* next;
};

// Estrutura para representar um grafo
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int isDirected;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com 'numVertices' vértices
struct Graph* createGraph(int numVertices, int isDirected) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->isDirected = isDirected;

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona uma aresta do src ao dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (!graph->isDirected) {
        // Se não for um grafo dirigido, adicione também uma aresta do dest ao src
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// Função para remover uma aresta do grafo
void removeEdge(struct Graph* graph, int src, int dest) {
    // Remove a aresta do src ao dest
    struct Node* current = graph->adjLists[src];
    struct Node* prev = NULL;
    while (current != NULL && current->data != dest) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Aresta não encontrada.\n");
        return;
    }
    if (prev == NULL) {
        graph->adjLists[src] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);

    if (!graph->isDirected) {
        // Se não for um grafo dirigido, remova também a aresta do dest ao src
        current = graph->adjLists[dest];
        prev = NULL;
        while (current != NULL && current->data != src) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            graph->adjLists[dest] = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->adjLists[i];
        printf("Adjacências do vértice %d: ", i);
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
    printf("1. Grafo não dirigido\n");
    printf("2. Grafo dirigido\n");
    printf("Digite a opção (1 ou 2): ");
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