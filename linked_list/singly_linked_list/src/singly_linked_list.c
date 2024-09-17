#include "../include/singly_linked_list.h"

struct singly_linked_list LINKED_LIST = {.createNode=&createNode, .node_exists=&node_exists, .traverse=&traverse, .prepend=&prepend, .append=&append, .insert=&insert,
                                        .update=&update, .replace=&replace, .deleteHead=&deleteHead, .deleteTail=&deleteTail, .deleteNode=&deleteNode, .freeNodes=&freeNodes};
struct Node* createNode() {
    struct Node *node = malloc(sizeof(struct Node));
    if (!node) {
        fprintf(stderr, "Error : Memory allocation to create new node failed.\n");
        return NULL;
    }

    strcpy(node->data,"");
    node->next = NULL;
    return node;
}

bool is_head_null(struct Node **head) {
    if (!*head) {
        fprintf(stderr, "Error : Head is NULL.\n");
        return true;
    }
    return false;
}

bool is_tail_null(struct Node **head) {
    if (!*head) {
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

void traverse(struct Node *head) {
    struct Node *currentNode = head;
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
        return;
    }

    (*node)->next = *head;
    *head = *node;
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
        *tail = *head;
        return;
    }

    (*tail)->next = *node;
    (*node)->next = NULL;
    *tail = *node;
}

void insert(struct Node **head, struct Node **tail, struct Node **node, size_t index) {
    if (!*node) {
        fprintf(stderr, "Error : Cannot insert a NULL node.\n");
        return;
    }

    if (node_exists(head, node)) return;

    if (is_head_null(head)) return;
    if (is_tail_null(tail)) return;

    if (index == 0) {
        prepend(head, tail, node);
        return;
    }

    if (index == -1) {
        append(head, tail, node);
        return;
    }

    // loop upto the position of the node just before the index
    struct Node *currentNode = *head;
    for (size_t i = 0; currentNode->next && i < index - 1; currentNode = currentNode->next, ++i);
    struct Node *tempNode = currentNode->next;
    currentNode->next = *node;
    (*node)->next = tempNode;
}

void update(struct Node **head, struct Node **tail, char *new_value, size_t index) {
    if (is_head_null(head)) return;
    if (is_tail_null(tail)) return;

    if (index == 0) {
        strcpy((*head)->data, new_value);
        return;
    }

    if (index == -1) {
        strcpy((*tail)->data, new_value);
        return;
    }

    struct Node *currentNode = *head;
    
    // Loop upto the node to be updated
    for (size_t i = 0; currentNode && i < index; currentNode = currentNode->next, ++i);
    strcpy(currentNode->data, new_value);
}

void replace(struct Node **head, struct Node **tail, struct Node **node, size_t index) {
    if (is_head_null(head)) return;
    if (is_tail_null(tail)) return;

    if (index == 0) {
       (*node)->next = (*head)->next;
        free(*head);
        *head = *node;
        return;
    }

    struct Node *currentNode, *tempNode;
    currentNode = *head;
    // Loop upto the node just before the one to be replaced
    for (size_t i = 0; currentNode->next && i < index - 1; currentNode = currentNode->next, ++i);
    tempNode = currentNode->next;
    free(currentNode->next);
    (*node)->next = tempNode->next;
    
    if (tempNode == *tail) {
        *tail = *node;
        (*tail)->next = NULL;
        return;
    }

    currentNode->next = *node;
}

void deleteHead(struct Node **head, struct Node **tail) {
    if (is_head_null(head)) return;
    if (is_tail_null(tail)) return;

    if (*head == *tail) {
        free(*head);
        *head = *tail = NULL;
        return;
    }

    struct Node *tempNode = (*head)->next;
    free(*head);
    *head = tempNode;
}

void deleteTail(struct Node **head, struct Node **tail) {
    if (is_head_null(head)) return;
    if (is_tail_null(tail)) return;

    if (*head == *tail) {
        free(*head);
        *head = *tail = NULL;
        return;
    }

    // Loop upto the node just before the tail
    struct Node *currentNode = NULL;
    for (currentNode = *head; currentNode && currentNode->next != *tail; currentNode = currentNode->next);
    free(*tail);
    currentNode->next = NULL;
    *tail = currentNode;
}

void deleteNode(struct Node **head, struct Node **tail, size_t index) {
    if (is_head_null(head)) return;
    if (is_tail_null(tail)) return;

    if (*head == *tail) {
        fprintf(stderr, "Error : deleteNode() -> head and node pointers need to be different");
        return;
    }

    if (index == 0) {
        deleteHead(head, tail);
        return;
    }

    if (index == -1) {
        deleteTail(head, tail);
        return;
    }

    struct Node *currentNode, *tempNode;
    currentNode = *head;
    // Loop upto the node just before the one to be deleted
    for (size_t i = 0; currentNode->next && i < index - 1; currentNode = currentNode->next, ++i);
    tempNode = currentNode->next;
    free(currentNode->next);

    if (tempNode == *tail) {
        *tail = currentNode;
        (*tail)->next = NULL;
        return;
    }

    currentNode->next = tempNode->next;
}

void freeNodes(struct Node **head) {
    struct Node *currentNode, *nextNode;
    for (currentNode = *head; currentNode; currentNode = nextNode) {
        nextNode = currentNode->next;
        free(currentNode);
    }
    *head = NULL;
}