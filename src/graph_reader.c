#include "graph_reader.h"

void get_header(FILE*in, int *nodes, int *start_ID, int *end_ID) {
    fscanf(in, "%d %d %d\n", nodes, start_ID, end_ID);
}

void get_node(FILE *in, int *links, short *weights, int file_pos, int node_count) {
    int read_ID;
    short temp;
    fseek(in, file_pos, SEEK_SET);
    fscanf(in, "%d (%hd %hd):", &read_ID, &temp, &temp);
    for (int i = 0; i < 4; i++) {
        fscanf(in, " [%d %hd]", &links[i], &weights[i]);
    }
}

void go_next_line(FILE *in) {
    char c;
    while((c = fgetc(in)) != '\n') {
        continue;
    }
}

void get_file_positions(FILE *in, int *positions, int node_count) {
    for (int i = 0; i < node_count; i++) {
        positions[i] = ftell(in);
        while (fgetc(in) != '\n');
    }
}