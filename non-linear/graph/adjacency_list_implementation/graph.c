#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct AdjNode {
    char data;
    struct AdjNode *next;
};

struct AdjList{
    struct AdjNode *head;
};

struct Graph {
    int count;
    int size;
    struct AdjList listArray[MAX_SIZE];
};

void initGraph(struct Graph *g) {
    g->count = 0;
    g->size = MAX_SIZE;
    
    // Initialize the listArray
    for (int i = 0; i < g->size; ++i) {
        g->listArray[i].head = NULL;
    }
}

void addNode(struct Graph *g, struct AdjNode *n) {
    if (g->count < g->size) {
        n->next = NULL;
        g->listArray[g->count++].head = n; 
    }
}

void addEdge(struct Graph *g, int src, int dest) {
    struct AdjNode *n = malloc(sizeof(struct AdjNode));
    n->data = g->listArray[dest].head->data;
    n->next = g->listArray[src].head->next;
    g->listArray[src].head->next = n;
}

void printGraph(struct Graph *g) {
    printf("\nADJACENCY LISTS\n");
    for (int i = 0; i < g->size; ++i) {
        printf("%c : ", g->listArray[i].head->data);
        while (g->listArray[i].head) {
            if (g->listArray[i].head->next) {
                printf("%c ", g->listArray[i].head->next->data);
            }
            g->listArray[i].head = g->listArray[i].head->next;
        }
        printf("\n");
    }
}

void clearGraph(struct Graph *g) {
    for (int i = 0; i < g->size; ++i) {
        struct AdjNode *n;
        while(g->listArray[i].head) {
            n = g->listArray[i].head->next;
            free(g->listArray[i].head);
            g->listArray[i].head = g->listArray[i].head->next;
        }
    }
    printf("\nGRAPH CLEARED!!!\n");
}

int main() {
    struct Graph g;
    initGraph(&g);

    struct AdjNode n1 = {'A'};
    struct AdjNode n2 = {'B'};
    struct AdjNode n3 = {'C'};
    struct AdjNode n4 = {'D'};
    struct AdjNode n5 = {'E'};

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

    printGraph(&g);
    clearGraph(&g);

    return 0;
}