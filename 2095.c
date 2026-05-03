#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    int n = 0, middle;
    struct ListNode *i, *temp;

    if (head->next == NULL) {
        return NULL;
    }

    for (i = head; i != NULL; i = i->next) {
        n++;
    }

    middle = n / 2;
    i = head;

    for (int j = 1; j < middle; j++) {
        i = i->next;
    }

    temp = i->next;
    i->next = i->next->next;
    free(temp);

    return head;
}