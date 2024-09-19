#include "../include/dequeue.h"

int main() {
    struct Dequeue d;
    init(&d);

    enqueue_front(&d, "Andrew");
    enqueue_front(&d, "Muchangi");
    enqueue_front(&d, "James");
    enqueue_front(&d, "Asterix");
    printDequeue(&d);

    enqueue_end(&d, "Adam");
    enqueue_end(&d, "Eve");
    enqueue_end(&d, "Lucy");
    printDequeue(&d);

    char *d1 = dequeue_front(&d);
    printf("Dequeued -> %s\n", d1);
    printDequeue(&d);

    char *d2 = dequeue_end(&d);
    printf("Dequeued -> %s\n", d2);
    printDequeue(&d);

    return 0;
}