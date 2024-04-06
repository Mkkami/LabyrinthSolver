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

int createNode(Graph *graph, int *w, int *c, int id) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "createNode: Memory allocation fail\n");
        return -1;
    }
    node->ID = id;
    int index;
    while (w[index] > 0) {
        node->weight[index] = w[index];
        node->connections[index] = c[index];
        index++;
    }
    graph->node_list[id] = node;
    return 0;
}

Position *createPositionList(int node_count) {
    Position *pos = malloc(sizeof(Position)*node_count);
    for (int i = 0; i < node_count; i++) {
        pos[i].x = 0;
        pos[i].y = 0;
    }
    return pos;
}

void printGraph(Graph *graph, Position *position) {
    for (int i = 0; i < graph->node_count; i++) {
        //printf("%d \n", graph->node_list[i]->ID);
        printf("(%d %d)\n %d", position[i].x, position[i].y, i);
        //printf("%d (%d %d)\n", graph->node_list[i]->ID, position[i].x, position[i].y);
    }
}

int fillGraph(Graph *graph, Position *position, FILE *in) {
    int *pos = malloc(sizeof(int) * 2);
    int id;
    int *w = malloc(sizeof(int) * 4);
    int *c = malloc(sizeof(int) * 4);
    //works to this point
    int connection_index = 0;
    int *temp = malloc(sizeof(int) * 2);
    char character;

    for (int i = 0; i < graph->node_count; i++) {
        for (int j = 0; j < 4; j++) {
            w[j] = -1;      //change it to -1 so i know there
        }                   // is no connection

        // get id, position, connection x n
        fscanf(in, "%d ", &id);             //get id

        get_ID_position(pos, in);
        position[i].x = pos[0];
        position[i].y = pos[1];     
        printf("id: %d, position: %d, %d\n", id, pos[0], pos[1]);

        if (fscanf(in, "%c", &character) == 0 || character != ':') {    //dziala
            fprintf(stderr, "main.c: Error in graph file.\n");
            fprintf(stderr, "Expected ':', got '%c'", character);
            return 1;
        }   
        while (get_connection(temp, in) != 0) {     
            c[connection_index] = temp[0];
            w[connection_index] = temp[1];
            connection_index++;
        }

        // save everything to node

        if (createNode(graph, w, c, id) == -1) {
            return -1;
        }

        // fscanf skips \n so no need to check it

    }
    return 0;
}