#include "../include/singly_linked_list.h"

void initHead(struct Node **head);
void initTail(struct Node **tail);
void link_head_to_tail(struct Node **head, struct Node **tail);
struct Node* createNode();
void printList();
void prepend(struct Node **node);
void append(struct Node **node);
void deleteHead();
void deleteTail();
void deleteNode(size_t index);
size_t get_size();

struct singly_linked_list SINGLY_LINKED_LIST = {
    .head=NULL,
    .tail=NULL,
    .initHead=&initHead,
    .initTail=&initTail,
    .link_head_to_tail=&link_head_to_tail,
    .createNode=&createNode,
    .printList=&printList,
    .prepend=&prepend,
    .append=&append,
    .deleteHead=&deleteHead,
    .deleteTail=&deleteTail,
    .deleteNode=&deleteNode,
    .get_size=&get_size,
};

void initHead(struct Node **head) {
    if (!*head) {
        fprintf(stderr, "Error : Failed to initialize head, pointer to head is null.\n");
        return;
    }
    SINGLY_LINKED_LIST.head = *head;
}

void initTail(struct Node **tail) {
    if (!*tail) {
        fprintf(stderr, "Error : Failed to initialize tail, pointer to tail is null.\n");
        return;
    }
    SINGLY_LINKED_LIST.tail = *tail;
}

// used for linking head to tail pointing at different memory blocks
void link_head_to_tail(struct Node **head, struct Node **tail) {
    if (!*head) {
        fprintf(stderr, "Error : Failed to link head to tail, pointer to head is null.\n");
        return;
    }
    if (!*tail) {
        fprintf(stderr, "Error : Failed to link head to tail, pointer to tail is null.\n");
        return;
    }
    (*head)->next = *tail;
}

void printList() {
    if (!SINGLY_LINKED_LIST.head) {
        fprintf(stderr, "Error : Failed to print singly linked list, list is empty.\n");
        return;
    }
    size_t i = 0;
    for (struct Node *curr = SINGLY_LINKED_LIST.head; curr; curr = curr->next) {
        printf("Node [%d] : %d\n", i, curr->data);
        ++i;
    }
}

struct Node* createNode() {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        fprintf(stderr, "Error : Memory allocation to create new node failed.\n");
        return NULL;
    }
    newNode->data = 0;
    newNode->next = NULL;
    return newNode;
}

void prepend(struct Node **node) {
    // ensuring the node to be prepended is not null
    if (!*node) {
        fprintf(stderr, "Error : Failed to prepend node, pointer to node is empty.\n");
        return;
    }

    // prepend to an empty list
    if (!SINGLY_LINKED_LIST.head) {
        SINGLY_LINKED_LIST.head = SINGLY_LINKED_LIST.tail = *node;
        return;
    }

    // prepend to a list with only one node
    if (SINGLY_LINKED_LIST.head == SINGLY_LINKED_LIST.tail) {
        (*node)->next = SINGLY_LINKED_LIST.head;
        SINGLY_LINKED_LIST.head = *node;
        SINGLY_LINKED_LIST.tail = SINGLY_LINKED_LIST.head->next;
        return;
    }

    // prepend to a list with multiple nodes
    (*node)->next = SINGLY_LINKED_LIST.head;
    SINGLY_LINKED_LIST.head = *node;
}

void append(struct Node **node) {
    // ensuring the node to be appended is not null
    if (!*node) {
        fprintf(stderr, "Error : Failed to append node, pointer to node is empty.\n");
        return;
    }

    // appending to an empty list
    if (!SINGLY_LINKED_LIST.head) {
        SINGLY_LINKED_LIST.head = SINGLY_LINKED_LIST.tail = *node;
        return;
    }

    // appending to a list with only one node
    if (SINGLY_LINKED_LIST.head == SINGLY_LINKED_LIST.tail) {
        SINGLY_LINKED_LIST.tail = *node;
        SINGLY_LINKED_LIST.head->next = SINGLY_LINKED_LIST.tail;
        return;
    }

    SINGLY_LINKED_LIST.tail->next = *node;
    SINGLY_LINKED_LIST.tail = *node;
}

void deleteHead() {
    // ensuring the head is not null
    if (!SINGLY_LINKED_LIST.head) {
        fprintf(stderr, "Error : Failed to delete head, head is null.\n");
        return;
    }
    
    // deleting head from a list with only one node
    if (SINGLY_LINKED_LIST.head == SINGLY_LINKED_LIST.tail) {
        free(SINGLY_LINKED_LIST.head);
        SINGLY_LINKED_LIST.head = NULL;
        return;
    }

    struct Node *tempNode = SINGLY_LINKED_LIST.head->next;
    free(SINGLY_LINKED_LIST.head);
    SINGLY_LINKED_LIST.head = tempNode;
}

void deleteTail() {
    // ensuring the head is not null
    if (!SINGLY_LINKED_LIST.head) {
        fprintf(stderr, "Error : Failed to delete tail, head is null.\n");
        return;
    }

    // deleting tail from a list with only one node
    if (SINGLY_LINKED_LIST.head == SINGLY_LINKED_LIST.tail) {
        free(SINGLY_LINKED_LIST.tail);
        SINGLY_LINKED_LIST.head = SINGLY_LINKED_LIST.tail = NULL;
        return;
    }

    struct Node *curr;
    for (curr = SINGLY_LINKED_LIST.head; curr->next != SINGLY_LINKED_LIST.tail; curr = curr->next);
    free(SINGLY_LINKED_LIST.tail);
    SINGLY_LINKED_LIST.tail = curr;
    SINGLY_LINKED_LIST.tail->next = NULL;
}

void deleteNode(size_t index) {

    // ensuring the index is not out of range
    if (index > get_size() - 1) {
        fprintf(stderr, "Error : Failed to delete Node, index out of range.\n");
        return;
    }

    // ensuring the head is not null
    if (!SINGLY_LINKED_LIST.head) {
        fprintf(stderr, "Error : Failed to delete node, head is null.\n");
        return;
    }

    if (index == 0) {
        deleteHead();
        return;
    }
    if (index == -1) {
        deleteTail();
        return;
    }

    size_t i = 0;
    struct Node *curr;
    for (curr = SINGLY_LINKED_LIST.head; curr->next && i < index - 1; curr = curr->next, ++i);

    if (curr->next == SINGLY_LINKED_LIST.tail) {
        free(SINGLY_LINKED_LIST.tail);
        SINGLY_LINKED_LIST.tail = curr;
        SINGLY_LINKED_LIST.tail->next = NULL;
        return;
    }

    struct Node *tempNode = curr->next->next;
    free(curr->next);
    curr->next = tempNode;
}

size_t get_size() {
    size_t count = 0;
    struct Node *curr;
    for (curr = SINGLY_LINKED_LIST.head; curr; curr = curr->next, ++count);
    return count;
}