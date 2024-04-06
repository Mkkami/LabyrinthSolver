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
    
    fscanf(in, "(%d %d)", &pos[0], &pos[1]);
    
}

int get_connection(int *connection, FILE *in) {

    if(fscanf(in, "%d %d", &connection[0], &connection[1]) == 2) {
        return 1;
    }
    return 0;

}