#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy, *last, *curr, *i, *temp;

    if (!head || !head->next) {
        return head;
    }

    dummy.next = head;
    last = head;
    curr = head->next;

    while (curr) {
        temp = curr->next;
        if (curr->val >= last->val) {
            last = last->next;
        } else {
            for (i = &dummy; i->next != NULL && i->next->val < curr->val; i = i->next);
            last->next = curr->next;
            curr->next = i->next;
            i->next = curr;
        }
        curr = temp;
    }

    return dummy.next;
}