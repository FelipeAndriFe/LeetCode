#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;

typedef struct {
    Stack *s1;
    Stack *s2;
} MyQueue;

Stack *CreateS() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->top = NULL;
    stack->size = 0;
    return stack;
}

bool IsEmptyS(Stack *stack) {
    return stack->size == 0;
}

void PushS(Stack *stack, int x) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) return;

    new->val = x;
    new->next = stack->top;
    stack->top = new;
    stack->size++;
}

int PopS(Stack *stack) {
    int x;
    Node *temp;

    if (IsEmptyS(stack)) {
        printf("Pop Failed\n");
        return -1;
    }

    x = stack->top->val;
    temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return x;
}

void Swap(Stack *src, Stack *dest) {
    int size = src->size;
    
    for (int i = 0; i < size; i++) {
        PushS(dest, PopS(src));
    }
}

void DestroyS(Stack *s) {
    Node *temp;
    while (s->top) {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    free(s);
}

MyQueue* myQueueCreate() {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    if (!q) return NULL;

    q->s1 = CreateS();
    if (!q->s1) {
        free(q);
        return NULL;
    }
    q->s2 = CreateS();
    if (!q->s2) {
        free(q->s1);
        free(q);
        return NULL;
    }
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    if (IsEmptyS(obj->s1)) {
        Swap(obj->s2, obj->s1);
    }
    PushS(obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
    if (IsEmptyS(obj->s2)) {
        Swap(obj->s1, obj->s2);
    }
    return PopS(obj->s2);
}

int myQueuePeek(MyQueue* obj) {
    if (IsEmptyS(obj->s2)) {
        Swap(obj->s1, obj->s2);
    }
    return obj->s2->top->val;
}

bool myQueueEmpty(MyQueue* obj) {
    return (IsEmptyS(obj->s1) && IsEmptyS(obj->s2));
}

void myQueueFree(MyQueue* obj) {
    DestroyS(obj->s1);
    DestroyS(obj->s2);
    free(obj);
}