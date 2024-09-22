#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Forward declaration of Node
struct Node;

struct singly_linked_list {
    struct Node *head;
    struct Node *tail;
    void (*initHead) (struct Node **head);
    void (*initTail) (struct Node **tail);
    void (*link_head_to_tail) (struct Node **head, struct Node **tail);
    struct Node* (*createNode) ();
    void (*printList) ();
    void (*prepend) (struct Node **node);
    void (*append) (struct Node **Node);
    void (*deleteHead) ();
    void (*deleteTail) ();
};

struct Node {
    int data;
    struct Node *next;
};

extern struct singly_linked_list SINGLY_LINKED_LIST;

#endif
