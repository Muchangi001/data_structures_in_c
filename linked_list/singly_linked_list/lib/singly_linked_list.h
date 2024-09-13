#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void traverse(struct Node*);

#endif