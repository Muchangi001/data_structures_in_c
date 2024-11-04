#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    char data;
} Node;

typedef struct {
    int count;
    int size;
    int matrix[MAX_SIZE][MAX_SIZE];
    Node nodes[MAX_SIZE];
} Graph;

void initGraph(Graph *g) {
    g->count = 0;
    g->size = MAX_SIZE;
    
    // Initialize the adjacency matrix to 0
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            g->matrix[i][j] = 0;
        }
    }
}

void addNode(Graph *g, Node *n) {
    if (g->count < g->size) {
        g->nodes[g->count++] = *n;
    }
}

void addEdge(Graph *g, int src, int dest) {
    // Dense Graph
    g->matrix[src][dest] = 1;
}

void printMatrix(Graph *g) {
    printf("\n");
    printf("ADJACENCY MATRIX\n\n");
    printf("    ");
    for (int i = 0; i < g->size; ++i) {
        printf("%c ", g->nodes[i].data);
    }
    printf("\n");
    printf("   -----------\n");
    for (int i = 0; i < g->size; ++i) {
        printf("%c | ", g->nodes[i].data);
        for (int j = 0; j < g->size; ++j) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("|\n");
    }
    printf("   -----------\n");
}

void printNodeConnection(Graph *g) {
    printf("\n");
    printf("NODE CONNECTION\n");
    for (int i = 0; i < g->size; ++i) {
        printf("%c : ", g->nodes[i].data);
        for (int j = 0; j < g->size; ++j) {
            if (g->matrix[i][j]) {
                printf("%c ", g->nodes[j].data);
            }
        }
        printf("\n");
    }
}

int main() {

    Graph g;
    initGraph(&g);

    Node n1 = {'A'};
    Node n2 = {'B'};
    Node n3 = {'C'};
    Node n4 = {'D'};
    Node n5 = {'E'};

    addNode(&g, &n1);
    addNode(&g, &n2);
    addNode(&g, &n3);
    addNode(&g, &n4);
    addNode(&g, &n5);

    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 2);

    printMatrix(&g);
    printNodeConnection(&g);
    
    return 0;
}