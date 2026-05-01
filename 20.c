#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char *items;
    int size;
}Stack;

Stack *Create(int cap);
void Destroy(Stack *stack);
void Push(Stack *stack, char item);
bool Pop(Stack *stack, char *item);
bool IsEmpty(Stack *stack);

bool isValid(char* s) {
    bool tryPop = true;
    char popped;
    Stack *stack = Create(strlen(s));

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ')') {
            tryPop = Pop(stack, &popped);
            if (popped != '(' || !tryPop) {
                Destroy(stack);
                return false;
            }
        } else if (s[i] == ']') {
            tryPop = Pop(stack, &popped);
            if (popped != '[' || !tryPop) {
                Destroy(stack);
                return false;
            }
        } else if (s[i] == '}') {
            tryPop = Pop(stack, &popped);
            if (popped != '{' || !tryPop) {
                Destroy(stack);
                return false;
            }
        } else {
            Push(stack, s[i]);
        }
    }

    if (!IsEmpty(stack)) {
        Destroy(stack);
        return false;
    }

    Destroy(stack);
    return true;
}

Stack *Create(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->items = (char *)malloc(sizeof(char)*cap);
    if (!stack->items) {
        free(stack);
        return NULL;
    }

    stack->size = 0;
    return stack;
}

void Destroy(Stack *stack) {
    free(stack->items);
    free(stack);
}

void Push(Stack *stack, char item) {
    stack->items[stack->size] = item;
    stack->size++;
}

bool Pop(Stack *stack, char *item) {
    if (IsEmpty(stack)) return false;
    stack->size--;
    *item = stack->items[stack->size];
    return true;
}

bool IsEmpty(Stack *stack) {
    return stack->size == 0;
}