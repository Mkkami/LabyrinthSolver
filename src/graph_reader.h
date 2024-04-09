#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include <stdio.h>
#include <stdlib.h>


int get_node_count(FILE*);
void get_start_end_ID(int*, FILE*); //[start, end]      
void get_ID_position(int*, FILE*); //[x, y]
int get_links(int*, int*, FILE*); // [id, weight] x 4

#endif