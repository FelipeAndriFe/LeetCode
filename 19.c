#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p1 = head, *p2 = head, *temp;

    if (head->next == NULL){
        free(head);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        p2 = p2->next;
    }

    if (p2 == NULL) {
        head = head->next;
        free(p1);
        return head;
    }

    for (; p2->next != NULL; p2 = p2->next) {
        p1 = p1->next;
    }

    temp = p1->next;
    p1->next = (p1->next)->next;
    free(temp);

    return head;
}