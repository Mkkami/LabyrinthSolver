#include "output.h"

void printPath(Position *pos, int previous[], FILE *out, int start_ID, int end_ID) {
    
    if (previous[end_ID] != -1) {
        int current = end_ID;
        fprintf(out, "Path: \n");
        while (current != start_ID) {
            fprintf(out, "%d %d\n", pos[current].x, pos[current].y);
            current = previous[current];
        }
        fprintf(out, "%d %d\n", pos[start_ID].x, pos[start_ID].y);
    } else {
        fprintf(out, "No path found.\n");
    }

}