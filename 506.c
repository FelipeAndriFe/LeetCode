#include <stdlib.h>

typedef struct Node {
    int val;
    int index;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *Create();
void Enqueue(Queue *q, int x, int index);
void Dequeue(Queue *q, int *index);
void Destroy(Queue *q);

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char **result = (char **)malloc(sizeof(char *) * scoreSize);
    if (!result) return NULL;
    for (int i = 0; i < scoreSize; i++) {
        result[i] = (char *)malloc(sizeof(char) * 13);
        if (!result[i]) return NULL;
    }

    Queue *q = Create();
    int index;
    if (!q) return NULL;

    for (int i = 0; i < scoreSize; i++) {
        Enqueue(q, score[i], i);
    }

    for (int i = 0; i < scoreSize; i++) {
        Dequeue(q, &index);
        if (i == 0) {
            strcpy(result[index], "Gold Medal");
        } else if (i == 1) {
            strcpy(result[index], "Silver Medal");
        } else if (i == 2) {
            strcpy(result[index], "Bronze Medal");
        } else {
            char str[10];
            sprintf(str, "%d", (i+1));
            strcpy(result[index], str);
        }
    }
    *returnSize = scoreSize;
    return result;
}

Queue *Create() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

void Enqueue(Queue *q, int x, int index) {
    Node *temp, *i;

    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) return;

    new->val = x;
    new->index = index;
    if (q->tail == NULL) {
        q->tail = new;
        q->head = new;
        new->next = NULL;
        new->prev = NULL;
    } else {
        for (i = q->tail; i != NULL && x > i->val; i = i->prev);
        if (i == NULL) {
            new->next = q->head;
            q->head->prev = new;
            q->head = new;
            new->prev = NULL;
        } else {
            new->prev = i;
            new->next = i->next;
            if (i->next != NULL) {
                i->next->prev = new;
            } else {
                q->tail = new;
            }
            i->next = new;
        }
    }
}

void Dequeue(Queue *q, int *index) {
    *index = q->head->index;
    Node *temp;

    temp = q->head;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    } else {
        q->head->prev = NULL;
    }
    free(temp);
}

void Destroy(Queue *q) {
    Node *temp;

    while (q->head) {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    free(q);
}