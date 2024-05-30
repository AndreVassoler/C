#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// Estrutura para representar um nó de lista de adjacências
struct Node {
    int data;
    struct Node* next;
};

// Estrutura para representar um grafo
struct Graph {
    struct Node* adjLists[MAX_VERTICES];
    int numVertices;
    int isDirected;
};

// Função para criar um novo nó de lista de adjacências
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

// Função de busca em profundidade (DFS)
void DFS(struct Graph* graph, int startVertex, int targetVertex, bool* visited, int* path, int* pathIndex) {
    // Marcamos o vértice atual como visitado
    visited[startVertex] = true;
    // Adicionamos o vértice atual ao caminho e incrementamos o índice
    path[(*pathIndex)++] = startVertex;

    // Verificamos se o vértice atual é o alvo que estamos procurando
    if (startVertex == targetVertex) {
        printf("Caminho encontrado: ");
        // Imprimimos o caminho percorrido até agora
        for (int i = 0; i < *pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        // Terminamos a execução da função, pois encontramos o caminho
        return;
    }

    // Inicializamos um ponteiro para o primeiro nó na lista de adjacência do vértice atual
    struct Node* current = graph->adjLists[startVertex];
    // Começamos um loop para iterar sobre todos os vértices adjacentes ao vértice atual
    while (current != NULL) {
        // Verificamos se o vértice adjacente atual já foi visitado
        if (!visited[current->data]) {
            // Se não foi visitado, chamamos recursivamente a função DFS para explorá-lo
            DFS(graph, current->data, targetVertex, visited, path, pathIndex);
        }
        // Avançamos para o próximo vértice adjacente na lista de adjacência
        current = current->next;
    }

    // Quando retornamos da chamada recursiva, decrementamos o índice do caminho, removendo o último vértice explorado
    (*pathIndex)--;
    // Desmarcamos o vértice atual como não visitado, para que ele possa ser explorado por outros caminhos
    visited[startVertex] = false;
}

// Função para realizar a busca em profundidade
void performDFS(struct Graph* graph, int startVertex, int targetVertex) {
    // Verificamos se os vértices fornecidos são válidos
    if (startVertex < 0 || startVertex >= graph->numVertices || targetVertex < 0 || targetVertex >= graph->numVertices) {
        printf("Vértices inválidos.\n");
        return;
    }

    // Array para rastrear quais vértices já foram visitados durante a busca
    bool visited[MAX_VERTICES];
    // Array para armazenar o caminho percorrido durante a busca
    int path[MAX_VERTICES];
    // Índice atual no array de caminho
    int pathIndex = 0;

    // Inicializamos todos os vértices como não visitados
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    // Imprimimos uma mensagem indicando o início da busca em profundidade
    printf("Iniciando busca em profundidade de %d para %d:\n", startVertex, targetVertex);
    // Chamamos a função DFS para realizar a busca em profundidade
    DFS(graph, startVertex, targetVertex, visited, path, &pathIndex);
    // Se nenhum caminho foi encontrado, imprimimos uma mensagem correspondente
    if (pathIndex == 0) {
        printf("Nenhum caminho encontrado.\n");
    }
}


// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    printf("Lista de Adjacências:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->adjLists[i];
        printf("Vértice %d: ", i);
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
    printf("Digite a opção (0 ou 1): ");
    scanf("%d", &isDirected);

    printf("Digite o número de vértices do grafo: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices, isDirected);

    int choice, src, dest, startVertex, targetVertex;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar conexão\n");
        printf("2. Remover conexão\n");
        printf("3. Realizar busca em profundidade\n");
        printf("4. Imprimir grafo\n");
        printf("5. Sair\n");
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
                printf("Digite o vértice de início da busca: ");
                scanf("%d", &startVertex);
                printf("Digite o vértice de destino da busca: ");
                scanf("%d", &targetVertex);
                performDFS(graph, startVertex, targetVertex);
                break;
            case 4:
                printGraph(graph);
                break;
            case 5:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}