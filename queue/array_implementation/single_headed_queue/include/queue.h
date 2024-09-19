#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10
#define DATA_SIZE 256

struct Queue {
    int head;
    int tail;
    char data[MAX_SIZE][DATA_SIZE];
};

void init (struct Queue *q);
int size(struct Queue *q);
void printQueue (struct Queue *q);
bool is_queue_ptr_null (struct Queue *q);
bool is_queue_empty (struct Queue *q);
void enqueue (struct Queue *q, char *dt);
char* dequeue (struct Queue *q);

#endif