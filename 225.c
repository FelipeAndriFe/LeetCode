#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} Queue;

typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;

Queue *CreateQ() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

void PushQ(Queue *q, int x) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) return;

    new->val = x;
    new->next = NULL;
    if (q->tail == NULL) {
        q->tail = new;
        q->head = new;
    } else {
        q->tail->next = new;
        q->tail = new;
    }
    q->size++;
}

int PopQ(Queue *q) {
    int x = q->head->val;
    Node *temp = q->head;

    q->head = q->head->next;
    free(temp);

    if (q->head == NULL) {
        q->tail = NULL;
    }
    q->size--;
    return x;
}

void DestroyQ(Queue *q) {
    Node *temp;
    
    while (q->head) {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    free(q);
}

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    if (!stack) return NULL;

    stack->q1 = CreateQ();
    stack->q2 = CreateQ();
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->q1->tail == NULL && obj->q2->tail == NULL) {
        PushQ(obj->q1, x);
    } else if (obj->q1->tail == NULL) {
        PushQ(obj->q2, x);
    } else {
        PushQ(obj->q1, x);
    }
}

int myStackPop(MyStack* obj) {
    int size;

    if (obj->q2->tail == NULL) {
        size = obj->q1->size;
        for (int i = 1; i < size; i++) {
            PushQ(obj->q2, PopQ(obj->q1));
        }
        return PopQ(obj->q1);
    } else {
        size = obj->q2->size;
        for (int i = 1; i < size; i++) {
            PushQ(obj->q1, PopQ(obj->q2));
        }
        return PopQ(obj->q2);
    }
}

int myStackTop(MyStack* obj) {
    int x, size;

    if (obj->q2->tail == NULL) {
        size = obj->q1->size;
        for (int i = 1; i < size; i++) {
            PushQ(obj->q2, PopQ(obj->q1));
        }
        x = PopQ(obj->q1);
        PushQ(obj->q2, x);
        return x;
    } else {
        size = obj->q2->size;
        for (int i = 1; i < size; i++) {
            PushQ(obj->q1, PopQ(obj->q2));
        }
        x = PopQ(obj->q2);
        PushQ(obj->q1, x);
        return x;
    }
}

bool myStackEmpty(MyStack* obj) {
    return (obj->q1->size == 0 && obj->q2->size == 0);
}

void myStackFree(MyStack* obj) {
    DestroyQ(obj->q1);
    DestroyQ(obj->q2);
    free(obj);
}