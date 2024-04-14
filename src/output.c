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