#include "graph_reader.h"
//#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *in = fopen(argv[1], "r");

    int nodes = 0;
    nodes = get_node_count(in);
    printf("Nodes: %d\n", nodes);

    int *start_end = malloc(sizeof(int) * 2);
    get_start_end_ID(start_end, in);
    printf("s: %d, e: %d\n", start_end[0], start_end[1]);

    //createGraph(Graph *graph)


    return 0;
}