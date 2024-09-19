#include "../include/stack.h"

void init (struct Stack *s) {
    if (is_stack_ptr_null(s)) return;
    s->top = -1;
    memset(s->data, '\0', sizeof(s->data));
}

void printStack (struct Stack *s) {
    if (is_stack_ptr_null(s)) return;
    if (is_stack_empty(s)) return;
    for (size_t i = 0; i <= s->top; ++i) printf("Data [%d] : %s\n", i, s->data[i]);
}

int size (struct Stack *s) {
    if (is_stack_ptr_null(s)) return -1;
    if (is_stack_empty(s)) return 0;
    return s->top + 1;
}

bool is_stack_ptr_null (struct Stack *s) {
    if (!s) {
        fprintf(stderr, "Error : Pointer to stack is NULL.\n");
        return true;
    }
    return false;
}

bool is_stack_empty (struct Stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Error : Stack is empty.\n");
        return true;
    }
    return false;
}

bool is_stack_full (struct Stack *s) {
    if (s->top == MAX_SIZE - 1) {
        fprintf(stderr, "Error : Stack is empty.\n");
        return true;
    }
    return false;
}

void push (struct Stack *s, char *dt) {
    if (is_stack_ptr_null(s)) return;
    if (is_stack_full(s)) return;
    strcpy(s->data[++s->top], dt);
}

char* pop (struct Stack *s) {
    if (is_stack_ptr_null(s)) return NULL;
    if (is_stack_empty(s)) return NULL;

    static char popped_item[sizeof(s->data)/sizeof(s->data[0])];
    strcpy(popped_item, s->data[s->top]);
    strcpy(s->data[s->top], "\0");

    if (!s->top) s->top = -1; // handle popping if there is only one item in the stack
    else --s->top;

    return popped_item;
}

void peek (struct Stack *s) {
    if (is_stack_ptr_null(s)) return;
    if (is_stack_empty(s)) return;
    printf("Peek() -> Node[%d] : %s\n", s->top, s->data[s->top]);
}