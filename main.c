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
        fprintf(stderr,"Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = value;
}

double pop(Stack *s) {
    if (isStackEmpty(s)) {
        fprintf(stderr, "Not Suitable Operations\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

double rpnCalculator(const char *expression) {
    Stack stack;
    initStack(&stack);
    const char *token = strtok((char *)expression, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atof(token));
        } else if (strlen(token) == 1) {
            double b = pop(&stack);
            double a = pop(&stack);
            switch (token[0]) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/':
                    if (b == 0) {
                        fprintf(stderr, "Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, a / b);
                    break;
                default:
                    fprintf(stderr, "Unknown operator: %s\n", token);
                    exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "Invalid token: %s\n", token);
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ");
    }
    if (stack.top != 0) {
        fprintf(stderr, "Invalid RPN expression\n");
        exit(EXIT_FAILURE);
    }
    return pop(&stack);
}

// Dependency completed

int main() {
    char expression[256];
    printf("Enter an RPN expression: ");
    if (fgets(expression, sizeof(expression), stdin) != NULL) {
        expression[strcspn(expression, "\n")] = 0;
        double result = rpnCalculator(expression);
        printf("Result: %lf\n", result);
    }
    else {
        fprintf(stderr, "Error reading input\n");
    }

    return 0;

}
