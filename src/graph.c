#include "graph.h"


Node createNode(int id, int c[], short w[]) {
    Node node;
    node.ID = id;
    for (int i = 0; i < 4; i++) {
        node.weight[i] = w[i];
        node.connections[i] = c[i];
    }
    return node;
}

