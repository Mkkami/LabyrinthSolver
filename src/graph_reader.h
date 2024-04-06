#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include <stdio.h>


int get_node_count(FILE *in);
void get_start_end_ID(int *start_end, FILE *in); //[start, end]      
void get_ID_position(int *pos, FILE *in); //[x, y]
int get_connection(int *connection, FILE *in); // [id, weight] x 4

#endif