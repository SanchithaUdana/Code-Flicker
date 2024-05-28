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

void push(Stack * s,double value ) {
    if(isStackFull(s)){
        fprintf(stderr,"Hello World\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = value;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
