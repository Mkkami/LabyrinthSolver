#include "graph_reader.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *in = fopen(argv[1], "r");

    int node_count = 0;
    node_count = get_node_count(in);
    printf("Nodes: %d\n", node_count);

    int start_end[2];
    get_start_end_ID(start_end, in);
    printf("s: %d, e: %d\n", start_end[0], start_end[1]);
 

    Graph *graph = createGraph(node_count);
    Position *position = createPositionList(node_count);

    fillGraph(graph, position, in);

    printGraph(graph, position);

    //printf("%d\n", graph->node_list[50]->ID);

    freeGraph(graph);
    free(position);


    return 0;
}