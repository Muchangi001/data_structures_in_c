#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DATA_SIZE 256

struct Node {
    char data[DATA_SIZE];
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode();
bool is_head_null(struct Node **node); // checks if a the head node is NULL
bool is_tail_null(struct Node **tail); // checks if the tail node is NULL
bool node_exists(struct Node **head, struct Node **node); // checks if a node exists
void print_list(struct Node **head); // traverses the linked list and prints the data of each node
void prepend(struct Node **head, struct Node **tail, struct Node **node); // prepends a node at the beginning of the linked list
void append(struct Node **head, struct Node **tail, struct Node **node); // appends a node at the end of the linked list
void insert(struct Node **head, struct Node **tail, struct Node **node, size_t index); // inserts a node at the specified position
void update(struct Node **head, struct Node **tail, char *new_value, size_t index); // Changes the data of a node in the linked list
void replace(struct Node **head, struct Node **tail, struct Node **node, size_t index); // replaces an existing node at the specified position with a new node
void deleteHead(struct Node **head, struct Node **tail); // deletes the head node
void deleteTail(struct Node **head, struct Node **tail); // deletes the tail node
void deleteNode(struct Node **head, struct Node **tail, size_t index); // deletes a specific node
void freeNodes(struct Node **head);

#endif