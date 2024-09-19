#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 10
#define DATA_SIZE 256

struct Stack {
    int top;
    char data[MAX_SIZE][DATA_SIZE];
};

void init (struct Stack *stack);
bool is_stack_ptr_null(struct Stack *stack);
bool is_stack_empty (struct Stack *s);
void printStack (struct Stack *stack);
void push (struct Stack *stack, char *data);
char* pop (struct Stack *s);
void peek (struct Stack *s);

#endif