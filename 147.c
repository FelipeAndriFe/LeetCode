#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void Insert(struct ListNode **p, int x) {
    struct ListNode *new, *i;
    new = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!new) return;

    new->val = x;
    new->next = NULL;

    if (*p == NULL) {
        *p = new;
    } else if ((*p)->val > x) {
        new->next = *p;
        *p = new;
    } else {
        for (i = *p; i->next != NULL && i->next->val < x; i = i->next);
        new->next = i->next;
        i->next = new;
    }
 }

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *result, *i;

    if (head->next == NULL) {
        return head;
    }

    for (i = head; i != NULL; i = i->next) {
        Insert(&result, i->val);
    }

    return result;
}