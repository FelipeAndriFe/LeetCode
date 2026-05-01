#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void Insert(struct ListNode **p, int x) {
    struct ListNode *i, *new;
    new = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!new) return;

    new->val = x;
    new->next = NULL;

    if (*p == NULL) {
        *p = new;
    } else {
        for (i = *p; i->next != NULL; i = i->next);
        i->next = new;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *i = list1, *j = list2, *result;

    if (!list1 && !list2) {
        return NULL;
    } else if (!list1) {
        return list2;
    } else if (!list2) {
        return list1;
    }

    while (i != NULL && j != NULL) {
        if (i->val > j->val) {  
            Insert(&result, j->val);
            j = j->next;
        } else {
            Insert(&result, i->val);
            i = i->next;
        }
    }

    while (i != NULL) {
        Insert(&result, i->val);
        i = i->next;
    }

    while (j != NULL) {
        Insert(&result, j->val);
        j = j->next;
    }

    return result;
}