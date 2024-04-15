#include "graph_reader.h"

void get_header(FILE*in, int *nodes, int *start_ID, int *end_ID) {
    fscanf(in, "%d %d %d", nodes, start_ID, end_ID);
}

void get_node(FILE *in, int *links, short *weights, int ID, int node_count) {
    int read_ID;
    int temp;
    fscanf(in, "%d (%d %d):", &read_ID, &temp, &temp);
    if (read_ID > ID) {
        rewind(in);
        go_next_line(in);
        fscanf(in, "%d (%d %d):", &read_ID, &temp, &temp);
    }
     if (read_ID == ID) {
        // pass
    } else {
        while (read_ID < ID) {
            go_next_line(in);
            fscanf(in, "%d (%d %d):", &read_ID, &temp, &temp);
        }
    }
    for (int i = 0; i < 4; i++) {
        fscanf(in, " [%d %hd]", &links[i], &weights[i]);
    }

    if (read_ID == node_count-1 || read_ID == node_count) {
        rewind(in);
        go_next_line(in);
    }
}

void go_next_line(FILE *in) {
    char c;
    while((c = fgetc(in)) != '\n') {
        continue;
    }
}