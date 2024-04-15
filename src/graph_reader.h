#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include <stdio.h>
#include <stdlib.h>


void get_header(FILE*, int *, int *, int *);
void get_node(FILE *, int *, short *, int ID, int);
void go_next_line(FILE *);
void get_file_positions(FILE *, int *, int);

#endif