#include "../include/singly_linked_list.h"

int main() {
    struct Node *n1 = SINGLY_LINKED_LIST.createNode();
    n1->data = 1;

    struct Node *n2 = SINGLY_LINKED_LIST.createNode();
    n2->data = 2;

    /*

    Initializing head and tail pointing at the same memory block in the heap

    SINGLY_LINKED_LIST.initHead(&n1);
    SINGLY_LINKED_LIST.initHead(&n1);

    No need to link head to tail if they both point to the same memory block
   
    */

    // initializing head and tail pointing at different memory blocks
    SINGLY_LINKED_LIST.initHead(&n1);
    SINGLY_LINKED_LIST.initTail(&n2);

    // link head to tail if head and tail point to different memory blocks
    SINGLY_LINKED_LIST.link_head_to_tail(&n1, &n2);

    // prepending
    printf("\nprepending ...\n");
    struct Node *n3 = SINGLY_LINKED_LIST.createNode();
    n3->data = 3;
    SINGLY_LINKED_LIST.prepend(&n3);
    SINGLY_LINKED_LIST.printList();

    // appending
    printf("\nappending ...\n");
    struct Node *n4 = SINGLY_LINKED_LIST.createNode();
    n4->data = 4;
    SINGLY_LINKED_LIST.append(&n4);
    SINGLY_LINKED_LIST.printList();

    // inserting
    printf("\ninserting ...\n");
    struct Node *n5 = SINGLY_LINKED_LIST.createNode();
    n5->data = 5;
    SINGLY_LINKED_LIST.insert(&n5, 3);
    SINGLY_LINKED_LIST.printList();

    // deleting head
    printf("\ndeleting head ...\n");
    SINGLY_LINKED_LIST.deleteHead();
    SINGLY_LINKED_LIST.printList();
    
    // deleting tail
    printf("\ndeleting tail ...\n");
    SINGLY_LINKED_LIST.deleteTail();
    SINGLY_LINKED_LIST.printList();

    // deleting a Node
    printf("\ndeleting node ...\n");
    SINGLY_LINKED_LIST.deleteNode(0);
    SINGLY_LINKED_LIST.printList();
    
    printf("\nhead -> %d\ntail -> %d\n\n", SINGLY_LINKED_LIST.head->data, SINGLY_LINKED_LIST.tail->data);

    // freeing nodes from heap
    SINGLY_LINKED_LIST.freeNodes();
    
    return 0;
}
