#include "output.h"

void printPath(Position *pos, int previous[], FILE *out, int start_ID, int end_ID) {
    
    if (previous[start_ID] != -1) {
        int current = start_ID;
        fprintf(out, "Path: \n");
        while (current != end_ID) {
            fprintf(out, "%d %d\n", pos[current].x, pos[current].y);
            current = previous[current];
        }
        fprintf(out, "%d %d\n", pos[end_ID].x, pos[end_ID].y);
    } else {
        fprintf(out, "No path found.\n");
    }

}

Position *createPositionList(FILE*in, int node_count) {
    Position *pos = malloc(sizeof(Position)*node_count);
    if (pos == NULL) {
        fprintf(stderr, "graph.c: Position memory allocation fail\n");
        exit(EXIT_FAILURE);
    }
    short x, y;
    int temp;
    char c;

    for (int i = 0; i < node_count; i++) {
        
        fscanf(in, "%d (%hd %hd)", &temp, &x, &y);
        pos[i].x = x;
        pos[i].y = y;
        while ((c = fgetc(in)) != '\n') {
            continue;
        }
    }
    rewind(in);
    return pos;
}
