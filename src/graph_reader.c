#include "graph_reader.h"

int get_node_count(FILE *in) {
    int value;
    fscanf(in, "%d ", &value);
    return value;
}

void get_start_end_ID(int *start_end, FILE *in) {

    fscanf(in, "%d %d\n", &start_end[0], &start_end[1]);

}

void get_ID_position(int *pos, FILE *in) {
    
    if (fscanf(in, "(%d %d)", &pos[0], &pos[1]) != 2) {
        fprintf(stderr, "graph_reader.c: Error reading pos\n");
        exit(EXIT_FAILURE);
    }
    
}

int get_links(int *weight_temp, int* link_temp, FILE *in) {
    for (int i = 0; i < 4; i++) {
        if(fscanf(in, " [%d %d]", &link_temp[i], &weight_temp[i]) != 2) {
        return 0;
        }
    }
    return 1;
}