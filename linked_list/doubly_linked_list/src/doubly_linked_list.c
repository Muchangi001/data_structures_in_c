#include "../include/doubly_linked_list.h"

struct Node* createNode() {
    struct Node *node = malloc(sizeof(struct Node));
    if (!node) {
        fprintf(stderr, "Error : Memory allocation to create new node failed.\n");
        return NULL;
    }

    strcpy(node->data,"");
    node->next = NULL;
    node->prev = NULL;
    return node;
}

bool is_head_null(struct Node **head) {
    if (!*head) {
        fprintf(stderr, "Error : Head is NULL.\n");
        return true;
    }
    return false;
}

bool is_tail_null(struct Node **tail) {
    if (!*tail) {
        fprintf(stderr, "Error : Tail is NULL.\n");
        return true;
    }
    return false;
}

bool node_exists(struct Node **head, struct Node **node) {
    for (struct Node *currentNode = *head; currentNode; currentNode = currentNode->next) {
        if (currentNode == *node) {
            fprintf(stderr, "Error : Node already exists.\n");
            return true;
        } 
    }
    return false;
}

void print_list(struct Node **head) {
    struct Node *currentNode = *head;
    if (is_head_null(head)) return;
    printf("\n");
    printf("SINGLY_LINKED_LIST\n");
    for (size_t i = 0; currentNode; currentNode = currentNode->next, ++i) printf("Node[%d] : %s\n", i, currentNode->data);
    printf("\n");
}

void prepend(struct Node **head, struct Node **tail, struct Node **node) {

    // makes sure the node to be prepended is not NULL
    if (!*node) {
        fprintf(stderr, "Error : Cannot prepend a NULL node.\n");
        return;
    }

    // makes sure the node to be prepended does not exist in the linked list
    if (node_exists(head, node)) return;

    // checks if the list is empty
    if (!*head && !*tail) {
        *head = *node;
        *tail = *node;
        (*head)->next = (*tail)->next = NULL;
        return;
    }
    
    // makes sure the head node (only) is not NULL
    if (is_head_null(head)) return;

    // makes sure tail node (only) is not NULL
    if (is_tail_null(tail)) return;
    
    // checks if the list has only one node
    if (*head == *tail) {
        (*node)->next = *head;
        free(*head);
        *head = *node;
        
        *tail = (*head)->next;
        (*tail)->prev = *head;
        (*tail)->next = NULL;
        return;
    }

    (*node)->next = *head;
    (*head)->prev = *node;
    
    *head = *node;
    (*head)->prev = NULL;
}

void append(struct Node **head, struct Node **tail, struct Node **node) {
    if (!*node) {
        fprintf(stderr, "Error : Cannot append a NULL node.\n");
        return;
    }

    if (node_exists(head, node)) return;

    if (!*head && !*tail) {
        *head = *node;
        *tail = *node;
        (*head)->next = (*tail)->next = NULL;
        return;
    }
    
    if (is_head_null(head)) return;
    if (is_tail_null(tail)) return;

    if (*head == *tail) {
        (*node)->next = NULL;

        (*head)->next = *node;
        (*head)->prev = NULL;

        *tail = *node;

        return;
    }

    (*tail)->next = *node;
    (*node)->prev = *tail;
    
    (*node)->next = NULL;
    *tail = *node;
}