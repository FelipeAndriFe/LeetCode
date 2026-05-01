#include <stdlib.h>

typedef struct {
    int *items;
    int size;
}Stack;

Stack *Create(int cap);
void Destroy(Stack*stack);
void Push(Stack *stack, int item);
void Pop(Stack *stack, int *item);

int evalRPN(char** tokens, int tokensSize) {
    Stack *stack = Create(tokensSize);
    int op1, op2, result;

    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0) {
            Pop(stack, &op2);
            Pop(stack, &op1);
            result = op1 + op2;
            Push(stack, result);
        } else if (strcmp(tokens[i], "-") == 0) {
            Pop(stack, &op2);
            Pop(stack, &op1);
            result = op1 - op2;
            Push(stack, result);
        } else if (strcmp(tokens[i], "*") == 0) {
            Pop(stack, &op2);
            Pop(stack, &op1);
            result = op1 * op2;
            Push(stack, result);
        } else if (strcmp(tokens[i], "/") == 0) {
            Pop(stack, &op2);
            Pop(stack, &op1);
            result = op1 / op2;
            Push(stack, result);
        } else {
            op1 = atoi(tokens[i]);
            Push(stack, op1);
        }
    }

    if (tokensSize == 1) {
        Pop(stack, &result);
    }

    Destroy(stack);
    return result;
}

Stack *Create(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if ( !stack ) return NULL;

    stack->items = (int *)malloc(sizeof(int)*cap);
    if ( !stack->items ) {
        free(stack);
        return NULL;
    }

    stack->size = 0;
    return stack;
}

void Destroy(Stack*stack) {
    free(stack->items);
    free(stack);
}

void Push(Stack *stack, int item) {
    stack->items[stack->size] = item;
    stack->size++;
}

void Pop(Stack *stack, int *item) {
    stack->size--;
    *item = stack->items[stack->size];
}