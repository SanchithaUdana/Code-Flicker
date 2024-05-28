// Reverse Polish Calculator
// Programming 2 Group Assignment
// ------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double stack[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}


double rpnCalculator(const char *expression) {
    Stack stack;
    initStack(&stack);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
