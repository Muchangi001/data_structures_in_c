#include "../lib/singly_linked_list.h"

void traverse(struct Node *head) {
    struct Node *currentNode = head;
    printf("\n");
    printf("SINGLY_LINKED_LIST\n");
    for (size_t i = 0; currentNode != NULL; currentNode = currentNode->next) {
        printf("node[%zu] : %5d\n", i, currentNode->data);
    }
    printf("\n");
}