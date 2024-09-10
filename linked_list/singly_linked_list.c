// singly_linked_list.c
#include <stdio.h>
#include <stdlib.h>

// Foward declaration
struct singly_linked_list;

typedef struct singly_linked_list {
    int data;
    struct singly_linked_list *next;
} linked_list;

void append(linked_list**, linked_list*);
void prepend(linked_list**, linked_list*);
void insert(linked_list**, linked_list*, size_t);

void deleteHead(linked_list**);
void deleteTail(linked_list**, linked_list**);
void delete(linked_list**, linked_list**, size_t);

int main(void) {
    // Allocate memory separately for each node
    linked_list *head = (linked_list*) malloc(sizeof(linked_list));
    linked_list *node2 = (linked_list*) malloc(sizeof(linked_list));
    linked_list *node3 = (linked_list*) malloc(sizeof(linked_list));
    linked_list *node4 = (linked_list*) malloc(sizeof(linked_list));
    linked_list *node5 = (linked_list*) malloc(sizeof(linked_list));
    linked_list *node6 = (linked_list*) malloc(sizeof(linked_list));
    linked_list *node7 = (linked_list*) malloc(sizeof(linked_list));
    linked_list *node8 = (linked_list*) malloc(sizeof(linked_list));
    linked_list *node9 = (linked_list*) malloc(sizeof(linked_list));
    linked_list *tail = (linked_list*) malloc(sizeof(linked_list));

    // Accessing a node : O(1) = Constant time
    head->data = 1; node2->data = 2; node3->data = 3; node4->data = 4; node5->data = 5;
    node6->data = 6; node7->data = 7; node8->data = 8; node9->data = 9; tail->data = 10;
    
    head->next = node2; node2->next = node3; node3->next = node4; node4->next = node5; node5->next = node6,
    node6->next = node7; node7->next = node8; node8->next = node9; node9->next = tail; tail->next = NULL;

    // Prepending a node to the beginning of the singly linked list
    linked_list *firstNode = (linked_list*) malloc(sizeof(linked_list));
    firstNode->data = 0;
    firstNode->next = NULL;
    prepend(&head, firstNode);

    // Appending a node to the end of the singly linked list
    linked_list *lastNode = (linked_list*) malloc(sizeof(linked_list));
    lastNode->data = 11;
    lastNode->next = NULL;
    append(&tail, lastNode);

    // Inserting a node at a specific position
    linked_list *newNode = (linked_list*) malloc(sizeof(linked_list));
    newNode->data = 20;
    newNode->next = NULL;
    insert(&head, newNode, 0);

    // Deleting head
    deleteHead(&head);

    //Deleting tail
    deleteTail(&head, &tail);

    //Traversing a singly linked list : O(n) -> Linear time
    for (linked_list *currentNode = head; currentNode != NULL; currentNode = currentNode->next) {
        printf("Node data : %d\n", currentNode->data);
    }

    // Freeing the nodes from the heap
    linked_list *currentNode = head;
    linked_list *nextNode = NULL;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    return 0;
}

void append(linked_list **tail, linked_list *node) {
    (*tail)->next = node;
    node->next = NULL;
    *tail = node;
}

void prepend(linked_list **head, linked_list *node) {
    node->next = *head;
    *head = node;
}

void insert(linked_list **head, linked_list *node, size_t index) {
    linked_list **currentNode = head;
    size_t steps = index;

    if (index == 0) {
        node->next = *head;
        *head = node;
        return;
    }

    for (size_t i = 0; i < steps; ++i) {
        currentNode = &(*currentNode)->next;
        if (i == steps - 1) {
            linked_list *tempNode = *currentNode;
            node->next = tempNode->next;
            (*currentNode)->next = node;
            break;
        }  
    }
}

void deleteHead(linked_list **head) {
    linked_list *nextNode = (*head)->next;
    free(*head);
    *head = nextNode;
}

void deleteTail(linked_list **head, linked_list **tail) {
    for (linked_list **currentNode = head; *currentNode != NULL; currentNode = &(*currentNode)->next) {
        if ((*currentNode)->next->next == *tail) {
            linked_list *prev = (*currentNode)->next;
            free(*tail);
            *tail = prev;
        }
    }
}

void delete(linked_list **head, linked_list **tail, size_t index) {
    if (index == 0) {
        linked_list **tempHead = head;
        free(*head);
        *head = (*tempHead)->next;
    }

    
}