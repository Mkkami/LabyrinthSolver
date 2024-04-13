#include "priority_queue.h"

PriorityQueue *createQueue() {
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->size = 2;
    pq->last = -1;
    pq->array = malloc(pq->size * sizeof(PQNode));
    return pq;
}

PQNode createPQNode(int ID, unsigned short len) {
    PQNode node = {ID, len};
    return node;
}
void insert(PriorityQueue *pq, PQNode *node) {
    if (pq->last == pq->size-1) {       //if pq->last = 1, then pq->size = 2 (there are 2 elems)
        pq->size++;
        pq->array = realloc(pq->array, (pq->size)*sizeof(PQNode));
        if (pq->array == NULL) {
            fprintf(stderr,"priority_queue.c: Realloc failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    if (pq->last == -1) {
        pq->array[0] = *node;
    } else {
        int i = pq->last;
        while (i >= 0 && node->len < pq->array[i].len) {
            pq->array[i+1] = pq->array[i];
            i--;
        }
        pq->array[i+1] = *node;
    }
    pq->last++;
    //printf("change: %d\n", pq->last);

}

void printPQ(PriorityQueue *pq) {
    for (int i = 0; i <= pq->last; i++) {
        printf("(%d %d)", pq->array[i].ID, pq->array[i].len);
    }
}

PQNode pop(PriorityQueue* pq) {
    PQNode node = pq->array[0];
    int i = 0;
    while(i < pq->last) {
        pq->array[i] = pq->array[i+1];
        i++;
    }
    pq->last--;
    return node;
}

char is_empty(PriorityQueue* pq) {
    return pq->last == -1;
}

void freePQ(PriorityQueue *pq) {
    free(pq->array);
    free(pq);
}