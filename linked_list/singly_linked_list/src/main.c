#include "../lib/singly_linked_list.h"

int main() {
    struct Node *head;
    struct Node *node2;
    struct Node *node3;

    head = (struct Node*) malloc(sizeof(struct Node));
    node2 = (struct Node*) malloc(sizeof(struct Node));
    node3 = (struct Node*) malloc(sizeof(struct Node));

    head->data = 10;
    node2->data = 2;
    node3->data = 3;

    head->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Traversing a linked list : O(n) -> Linear time
    traverse(head);
    return 0;
}