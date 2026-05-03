#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct {
    struct ListNode *top;
    int size;
} Stack;

Stack *CreateS();
void Push(Stack *stack, int x);
int Pop(Stack *stack);
void InsertL(struct ListNode **list, int x);

struct ListNode* doubleIt(struct ListNode* head) {
    struct ListNode *result = NULL;
    Stack *stack = CreateS();
    int num, carry = 0;

    for (struct ListNode *i = head; i != NULL; i = i->next) {
        Push(stack, i->val);
    }

    while (stack->size > 0) {
        num = Pop(stack);
        num *= 2;

        if (num >= 10) {
            num -= 10;
            InsertL(&result, num + carry);
            carry = 1;
        } else {
            InsertL(&result, num + carry);
            carry = 0;
        }
    }

    if (carry == 1) {
        InsertL(&result, carry);
    }

    return result;
}

Stack *CreateS() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void Push(Stack *stack, int x) {
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!new) return;

    new->val = x;
    new->next = stack->top;
    stack->top = new;
    stack->size++;
}

int Pop(Stack *stack) {
    int x = stack->top->val;
    struct ListNode *temp;

    temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;

    return x;
}

void InsertL(struct ListNode **list, int x) {
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!new) return;

    new->val = x;
    new->next = *list;
    *list = new;
}