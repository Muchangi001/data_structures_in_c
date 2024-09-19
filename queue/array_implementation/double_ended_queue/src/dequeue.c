#include "../include/dequeue.h"

void init (struct Dequeue *d) {
    if (is_dequeue_ptr_null(d)) return;
    for (size_t i = 0; i < MAX_SIZE; ++i) strcpy(d->data[i], "\0");
    d->head = -1;
    d->tail = -1;
}

void printDequeue (struct Dequeue *d) {
    if (is_dequeue_ptr_null(d)) return;
    if (is_dequeue_empty(d)) return;
    printf("\n");
    for (size_t i = d->head; i <= d->tail; ++i) printf("Data [%d] : %s\n", i, d->data[i]);
    printf("\n");
}

bool is_dequeue_ptr_null(struct Dequeue *q) {
    if (!q) {
        fprintf(stderr, "Error : Pointer to Dequeue is NULL.\n");
        return true;
    }
    return false;
}

bool is_dequeue_empty(struct Dequeue *d) {
    if (d->head == d->tail && d->tail == -1) {
        fprintf(stderr, "Error : Dequeue is empty.\n");
        return true;
    }
    return false;
}

bool is_dequeue_full (struct Dequeue *q) {
    if (q->head == 0 && q->tail == MAX_SIZE - 1) {
        fprintf(stderr, "Error : Queue is full.\n");
        return true;
    }
    return false;
}

void copy_data(char dest[MAX_SIZE][DATA_SIZE], char src[MAX_SIZE][DATA_SIZE], size_t start_index, size_t end_index) {
    for (size_t i = start_index; i <= end_index; ++i) strcpy(dest[i], src[i]);
}

void enqueue_front (struct Dequeue *d, char *new_data) {
    if (is_dequeue_ptr_null(d)) return;
    if (is_dequeue_full(d)) return;

    if (d->head == d->tail && d->tail == -1) d->head = d->tail = 0; // checking if the dequeue has no items
    else ++d->tail;

    char temp_data[MAX_SIZE][DATA_SIZE];
    copy_data(temp_data, d->data, 0, MAX_SIZE - 1); // store a copy of the original data to temp_data

    strcpy(d->data[0], new_data); // store the new data as the first element in the dequeue

    for (size_t i = 0, j = 1; j < MAX_SIZE; ++i, ++j) { // update the dequeue
        strcpy(d->data[j], temp_data[i]);
    }
}

void enqueue_end(struct Dequeue *d, char *new_data) {
    if (is_dequeue_ptr_null(d)) return;
    if (is_dequeue_full(d)) return;

    if (d->head == d->tail && d->tail == -1) d->head = d->tail = 0; // checking if the dequeue has no items
    else ++d->tail;

    strcpy(d->data[d->tail], new_data);
}

char* dequeue_front (struct Dequeue *d) {
    if (is_dequeue_ptr_null(d)) return NULL;
    if (is_dequeue_empty(d)) return NULL;
    
    static char dequeued_item[DATA_SIZE];
    strcpy(dequeued_item, d->data[d->head]);

    if (d->head == d->tail) d->head = d->tail = -1;
    else --d->tail;

    char temp_data[MAX_SIZE][DATA_SIZE];
    // store a slice of dequeue elements in temp data beginning from the second element
    for (size_t i = 0, j = 1; j < MAX_SIZE; ++i, ++j) strcpy(temp_data[i], d->data[j]);

    // update dequeue elements to be same as temp_data
    copy_data(d->data, temp_data, 0, MAX_SIZE - 1);

    return dequeued_item;
}

char* dequeue_end(struct Dequeue *d) {
    if (is_dequeue_ptr_null(d)) return NULL;
    if (is_dequeue_empty(d)) return NULL;

    static char dequeued_item[DATA_SIZE];
    strcpy(dequeued_item, d->data[d->tail]);

    if (d->head == d->tail) d->head = d->tail = -1;
    else --d->tail;

    // removing the last item by replacing it with the null string
    strcpy(d->data[d->tail + 1], "\0");

    return dequeued_item;
}