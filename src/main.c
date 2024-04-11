#include "graph_reader.h"
#include "graph.h"
#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // FILE *in = fopen(argv[1], "r");

    // int node_count = 0;
    // node_count = get_node_count(in);
    // printf("Nodes: %d\n", node_count);

    // int start_end[2];
    // get_start_end_ID(start_end, in);
    // printf("s: %d, e: %d\n", start_end[0], start_end[1]);
 

    // Graph *graph = createGraph(node_count);
    // Position *position = createPositionList(node_count);

    // fillGraph(graph, position, in);

    // printGraph(graph, position);

    // //printf("%d\n", graph->node_list[50]->ID);

    // freeGraph(graph);
    // free(position);

    PriorityQueue *pq = createQueue();

    PQNode *node1 = createPQNode(1, 10);
    PQNode *node2 = createPQNode(2, 17);
    PQNode *node3 = createPQNode(3, 2);
    PQNode *node4 = createPQNode(4, 50);
    PQNode *node5 = createPQNode(5, 1);
    PQNode *node6 = createPQNode(6, 1399);
    
    insert(pq, node1);
    insert(pq, node2);
    insert(pq, node3);
    insert(pq, node4);
    insert(pq, node5);
    insert(pq, node6);

    printPQ(pq);

    PQNode *node = pop(pq);
    printf("\n%d %d\n", node->ID, node->len);
    free(node);

    printPQ(pq);

    freePQ(pq);

    return 0;
}