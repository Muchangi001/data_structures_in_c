#include "../include/singly_linked_list.h"

int main() {

    struct Node *head = LINKED_LIST.createNode();
    struct Node *tail = LINKED_LIST.createNode();

    strcpy(head->data, "Andrew");
    head->next = tail;

    strcpy(tail->data, "Muchangi");
    tail->next = NULL;

    // Prepending
    struct Node *newNode = LINKED_LIST.createNode();
    strcpy(newNode->data, "James");
    newNode->next = NULL;
    LINKED_LIST.prepend(&head, &tail, &newNode);
    LINKED_LIST.traverse(head);

    // Appending
    struct Node *newNode2 = LINKED_LIST.createNode();
    strcpy(newNode2->data, "John");
    newNode2->next = NULL;
    LINKED_LIST.append(&head, &tail, &newNode2);
    LINKED_LIST.traverse(head);

    // Inserting
    struct Node *newNode3 = LINKED_LIST.createNode();
    strcpy(newNode3->data, "Adam");
    newNode3->next = NULL;
    LINKED_LIST.insert(&head, &tail, &newNode3, 2); // 0 to prepend and -1 to append (special)
    LINKED_LIST.traverse(head);

    // Updating a Node
    LINKED_LIST.update(&head, &tail, "Eve", 2); // 0 to update head and -1 to update tail (special)
    LINKED_LIST.traverse(head);

    // Replacing a Node
    struct Node *newNode4 = LINKED_LIST.createNode();
    strcpy(newNode4->data, "Asterix");
    newNode4->next = NULL;
    LINKED_LIST.replace(&head, &tail, &newNode4, 2);
    LINKED_LIST.traverse(head);

    // Delete Head
    LINKED_LIST.deleteHead(&head, &tail);
    LINKED_LIST.traverse(head);

    // Delete Tail
    LINKED_LIST.deleteTail(&head, &tail);
    LINKED_LIST.traverse(head);

    // Delete Node
    LINKED_LIST.deleteNode(&head, &tail, 0);
    LINKED_LIST.traverse(head);

    return 0;
}