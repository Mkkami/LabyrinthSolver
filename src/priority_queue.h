#ifndef _PQ_H
#define _PQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct PQNode {
    int ID;
    unsigned short len;
} PQNode;

typedef struct PriorityQueue {
    struct PQNode *array;
    int size;
    int last;
} PriorityQueue;


PriorityQueue *createQueue();
void insert(PriorityQueue*, PQNode*);                  //and sort
PQNode pop(PriorityQueue*);                       //return lowest
char is_empty(PriorityQueue*);
void printPQ(PriorityQueue *pq);
PQNode createPQNode(int ID, unsigned short len);
void freePQ(PriorityQueue *pq);

#endif