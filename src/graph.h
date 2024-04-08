#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int ID;
    int weight[4];          //if there is no connection, weight = -1
    int connections[4];
} Node;

typedef struct Graph {
    int node_count;
    struct Node **node_list;
} Graph;

typedef struct Position {
    int x;
    int y;
} Position;

Graph *createGraph(int);
int createNode(Graph*, int*, int*, int);
Position *createPositionList(int);
void printGraph(Graph*, Position*);
int fillGraph(Graph*, Position*, FILE*);

void freeArrays(int*, int*, int*, int*);


#endif