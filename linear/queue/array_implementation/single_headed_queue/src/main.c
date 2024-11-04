#include "../include/queue.h"

int main() {
    struct Queue q;
    init(&q);
    
    enqueue(&q, "Andrew");
    enqueue(&q, "Muchangi");
    enqueue(&q, "James");
    printf("size of queue -> %d\n", size(&q));
    printQueue(&q);

    char *d1 = dequeue(&q);
    printQueue(&q);
    printf("dequeued -> %s\n", d1);

    char *d2 = dequeue(&q);
    printQueue(&q);
    printf("dequeued -> %s\n", d2);

    char *d3 = dequeue(&q);
    printf("dequeued -> %s\n", d3);
    printf("size of queue -> %d\n", size(&q));
    printQueue(&q);

    return 0;
}