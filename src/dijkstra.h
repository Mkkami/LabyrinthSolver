#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include "priority_queue.h"
#include "graph.h"
#include "output.h"
#include "graph_reader.h"

int dijkstra(FILE *in, FILE*out, int start_ID, int end_ID, int node_count, int*);

#endif