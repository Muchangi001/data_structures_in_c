#include "../include/doubly_linked_list.h"

int main() {
    struct Node *head = createNode();
    struct Node *tail = createNode();

    strcpy(head->data, "Andrew");
    head->next = tail; 
    
    strcpy(tail->data, "James");
    
    // prepending
    struct Node *n1 = createNode();
    strcpy(n1->data, "Eve");
    prepend(&head, &tail, &n1);
    print_list(&head);

    // appending
    struct Node *n2 = createNode();
    strcpy(n2->data, "Asterix");
    append(&head, &tail, &n2);
    print_list(&head);

    printf("prev <- %s\nnext -> %s\n", head->next->next->prev, head->next->next->next);
    return 0;
}