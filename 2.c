#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
void Insert(struct ListNode **p, int x) {

    struct ListNode *i, *new;
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    if ( !new ) exit(1);

    new->val = x;
    new->next = NULL;

    if ( *p == NULL ) {
        *p = new;
        return;
    }

    i = *p;
    while ( i->next != NULL ) {
        i = i->next;
    }

    i->next = new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int x, carry = 0;
    struct ListNode *i, *j, *answer = NULL;

    i = l1;
    j = l2;

    while ( i != NULL || j != NULL ) {
        if ( i == NULL ) {
            x = j->val + carry;
            j = j->next;
        } else if ( j == NULL ) {
            x = i->val + carry;
            i = i->next;
        } else {
            x = i->val + j->val + carry;
            i = i->next;
            j = j->next;
        }
        carry = 0;
        if ( x >= 10 ) {
            x = x % 10;
            carry = 1;
        }
        Insert(&answer, x);
    }

    if ( carry == 1 ) {
        Insert(&answer, carry);
    }

    return answer;
}