#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy, *prev, *first, *second;

    if (!head || !head->next) {
        return head;
    }

    dummy.next = head;
    prev = &dummy;

    while (prev->next && prev->next->next) {
        first = prev->next;
        second = prev->next->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }

    return dummy.next;
}