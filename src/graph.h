#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int ID;
    short weight[4];          //if there is no connection, weight = -1
    int connections[4];
} Node;


Node createNode(int, int[], short[]);


#endif