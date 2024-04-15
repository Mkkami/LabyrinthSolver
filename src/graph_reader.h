#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include <stdio.h>
#include <stdlib.h>


void get_header(FILE*in, int *nodes, int *start_ID, int *end_ID);
void get_node(FILE *in, int *links, short *weights, int ID, int node_count);
void get_positions(FILE *in, short *x, short *y);
void go_next_line(FILE *in);

#endif