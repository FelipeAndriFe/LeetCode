#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;

    if (!head || !head->next) {
        return;
    }

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *first = head;
    struct ListNode *second = slow->next;
    slow->next = NULL;

    struct ListNode *next = NULL, *curr = second, *prev = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    second = prev;

    while (second) {
        struct ListNode *temp1 = first->next;
        struct ListNode *temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}