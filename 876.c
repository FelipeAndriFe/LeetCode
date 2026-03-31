//Descrição: dada uma lista encadeada com cabeça, encontrar e retornar a celula do meio.

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* middleNode(struct ListNode* head) {
    int nodeCount = 1, middle;
    struct ListNode* result, *i;
    for (i = head; i->next != NULL; i = i->next){
        nodeCount++;
    }
    middle = (nodeCount/2)+1;
    nodeCount = 1;
    i = head;

    while(nodeCount != middle){
        nodeCount++;
        i = i->next;
    }

    result = i;
    return result;
}