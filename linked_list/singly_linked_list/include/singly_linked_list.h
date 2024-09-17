#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DATA_SIZE 256

// Forward declaration of Node
struct Node;

struct singly_linked_list {
    struct Node* (*createNode) ();
    bool (*node_exists) (struct Node **head, struct Node **node);
    void (*traverse) (struct Node *head);
    void (*prepend) (struct Node **head, struct Node **tail, struct Node **node);
    void (*append) (struct Node **head, struct Node **tail, struct Node **node);
    void (*insert) (struct Node **head, struct Node **tail, struct Node **node, size_t index);
    void (*update) (struct Node **head, struct Node **tail, char *new_value, size_t index);
    void (*replace) (struct Node **head, struct Node **tail, struct Node **node, size_t index);
    void (*deleteHead) (struct Node **head, struct Node **tail);
    void (*deleteTail) (struct Node **head, struct Node **tail);
    void (*deleteNode) (struct Node **head, struct Node **tail, size_t index);
    void (*freeNodes) (struct Node **head);
};

struct Node {
    char data[DATA_SIZE];
    struct Node *next;
};

extern struct singly_linked_list LINKED_LIST;

struct Node* create_new_node();
bool is_head_null(struct Node **node); // checks if a the head node is NULL
bool is_tail_null(struct Node **tail); // checks if the tail node is NULL
bool node_exists(struct Node **head, struct Node **node); // checks if a node exists
void traverse(struct Node *head); // traverses the linked list and prints the data of each node
void prepend(struct Node **head, struct Node **tail, struct Node **node); // prepends a node at the beginning of the linked list
void append(struct Node **head, struct Node **tail, struct Node **node); // appends a node at the end of the linked list
void insert(struct Node **head, struct Node **tail, struct Node **node, size_t index); // inserts a node at the specified position
void update(struct Node **head, struct Node **tail, char *new_value, size_t index); // Changes the data of a node in the linked list
void replace(struct Node **head, struct Node **tail, struct Node **node, size_t index); // replaces an existing node at the specified position with a new node
void deleteHead(struct Node **head, struct Node **tail); // deletes the head node
void deleteTail(struct Node **head, struct Node **tail); // deletes the tail node
void deleteNode(struct Node **head, struct Node **tail,size_t index); // deletes a specific node
void free_nodes(struct Node **head);

#endif
