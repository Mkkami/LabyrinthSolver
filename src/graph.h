#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int ID;
    int weight[4];
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

Graph *createGraph(int node_count);
int createNode(Graph *graph, int *w, int *c, int id);
Position *createPositionList(int node_count);
void printGraph(Graph *graph, Position *position);
int fillGraph(Graph *graph, Position *position, FILE *in);


#endif