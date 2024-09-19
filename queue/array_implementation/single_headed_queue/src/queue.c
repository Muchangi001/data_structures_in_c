#include "../include/queue.h"

void init (struct Queue *q) {
    if (is_queue_ptr_null(q)) return;
    q->head = -1;
    q->tail = -1;
}

int size(struct Queue *q) {
    if (is_queue_ptr_null(q)) return -1;
    if (is_queue_empty(q)) return 0;
    if (q->head == q->tail) return 1;
    return q->tail + 1;
}

bool is_queue_ptr_null (struct Queue *q) {
    if (!q) {
        fprintf(stderr, "Error : pointer to queue is NULL.\n");
        return true;
    }
    return false;
}

bool is_queue_empty (struct Queue *q) {
    if (q->head == q->tail && q->tail== -1) {
        fprintf(stderr, "Error : Queue is empty.\n");
        return true;
    }
    return false;
}

bool is_queue_full (struct Queue *s) {
    if (s->head == 0 && s->tail == MAX_SIZE - 1) {
        fprintf(stderr, "Error : Queue is full.\n");
        return true;
    }
    return false;
}

void printQueue (struct Queue *s) {
    if (is_queue_ptr_null(s)) return;
    if (is_queue_empty(s)) return;
    printf("SINGLE_ENDED_QUEUE\n");
    for (size_t i = 0; i <= s->tail; ++i) printf("Data [%d] : %s\n", i, s->data[i]);
    printf("\n");
}

void enqueue(struct Queue *q, char *dt) {
    if (is_queue_ptr_null(q)) return;
    if (is_queue_full(q)) return;

    if (q->head == q->tail && q->tail == -1) q->head = q->tail = 0; // checking if the queue has no items
    else ++q->tail;

    strcpy(q->data[q->tail], dt);
}

char* dequeue(struct Queue *q) {
    if (is_queue_ptr_null(q)) return NULL;
    if (is_queue_empty(q)) return NULL;
    
    static char dequeued_item[DATA_SIZE];
    strcpy(dequeued_item, q->data[q->tail]);
    strcpy(q->data[q->tail], "\0");

    if (q->head == q->tail) q->head = q->tail = -1; // handling dequeuing if the queue has only one element
    else --q->tail;
    return dequeued_item;
}