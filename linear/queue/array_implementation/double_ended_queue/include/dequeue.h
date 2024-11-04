#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX_SIZE 10
#define DATA_SIZE 256

struct Dequeue {
    int head;
    int tail;
    char data[MAX_SIZE][DATA_SIZE];
};

void init(struct Dequeue *d);
void printDequeue(struct Dequeue *d);
bool is_dequeue_ptr_null(struct Dequeue *q);
bool is_dequeue_empty(struct Dequeue *q);
bool is_dequeue_full(struct Dequeue *q);
void enqueue_front(struct Dequeue *d, char *new_data);
void enqueue_end(struct Dequeue *d, char *new_data);
char* dequeue_front(struct Dequeue *d);
char* dequeue_end(struct Dequeue *d);



#endif