#include "../include/stack.h"

int main () {
    struct Stack s;
    init(&s);
    push(&s, "Andrew");
    push(&s, "Muchangi");
    push(&s, "Eve");
    printStack(&s);

    char *popped = pop(&s);
    printf("Popped item -> %s\n", popped);

    peek(&s);
    printStack(&s);
    return 0;
}