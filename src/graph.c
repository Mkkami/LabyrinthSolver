#include "graph.h"
#include "graph_reader.h"

Graph* createGraph(int node_count) {
    Graph *graph = malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "createGraph: Memory allocation fail\n");
        exit(EXIT_FAILURE);
    }
    graph->node_list = malloc(node_count * sizeof(Node*));
    if (graph->node_list == NULL) {
        fprintf(stderr, "createGraph: Memory allocation fail\n");
        exit(EXIT_FAILURE);
    }
    graph->node_count = node_count;
    return graph;
}

int createNode(Graph *graph, short w[], int c[], int id) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "createNode: Memory allocation fail\n");
        return -1;
    }
    node->ID = id;
    node->visited = 0;
    int index = 0;
    while (w[index] > 0 && index < 4) {
        node->weight[index] = w[index];
        node->connections[index] = c[index];
        index++;
    }
    graph->node_list[id] = node;
    return 0;
}

Position *createPositionList(int node_count) {
    Position *pos = malloc(sizeof(Position)*node_count);
        if (pos == NULL) {
        fprintf(stderr, "graph.c: Position memory allocation fail\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < node_count; i++) {
        pos[i].x = 0;
        pos[i].y = 0;
    }
    return pos;
}

void printGraph(Graph *graph, Position *position) {
    for (int i = 0; i < graph->node_count; i++) {
        
        printf("id: %d pos: (%hd, %hd), connections:\t", graph->node_list[i]->ID, position[i].x, position[i].y);
        for (int j = 0; graph->node_list[i]->weight[j] > 0 && j < 4; j++) {
            printf("(%d %d) ", graph->node_list[i]->connections[j], graph->node_list[i]->weight[j]);
        }
        printf("\n");
    }
}

int fillGraph(Graph *graph, Position *position, FILE *in) {
    short pos[2];
    int id;
    short weight_temp[4];
    int link_temp[4];
    char character;

    for (int i = 0; i < graph->node_count; i++) {
        for (int j = 0; j < 4; j++) {
            weight_temp[j] = -1;      //change it to -1 so i know there
        }                   // is no connection

            //  GET ID
        if( fscanf(in, "%d ", &id) != 1) {
            fprintf(stderr, "graph.c: Error reading id from file.\n");
            return 1;
        }
        
            // GET AND SAVE POSITIONS
        get_ID_position(pos, in);
        position[i].x = pos[0];
        position[i].y = pos[1];     

            //  SKIP THE ":"
        if (fscanf(in, "%c", &character) == 0 || character != ':') {
            fprintf(stderr, "main.c: Error in graph file.\n");
            fprintf(stderr, "Expected ':', got '%c'", character);
            return 1;
        }   
            //  GET EVERY LINK
        if (get_links(weight_temp, link_temp, in) != 1) {
            fprintf(stderr, "graph.c: Error in graph file.\n");
            fprintf(stderr, "Link bad\n");
            return 1;
        }

            //  save everything to node
        if (createNode(graph, weight_temp, link_temp, id) == -1) {
            fprintf(stderr, "graph.c: Error in creating node.\n");
            return -1;
        }

        // fscanf skips \n so no need to check it

    }

    return 0;
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->node_count; i++) {
        free(graph->node_list[i]);
    }
    free(graph->node_list);
    free(graph);
}
