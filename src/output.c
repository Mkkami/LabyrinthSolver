#include "output.h"

void printPath(int *positions, int previous[], FILE*in, FILE *out, int start_ID, int end_ID) {

    short x, y;

    if (previous[start_ID] != -1) {
        int current = start_ID;
        fprintf(out, "Path: \n");
        while (current != end_ID) {

            get_pos(in, positions[current], &x, &y);
            fprintf(out, "%hd %hd\n", x, y);
            current = previous[current];

        }
        get_pos(in, positions[current], &x, &y);
        fprintf(out, "%hd %hd\n", x, y);

    } else {
        fprintf(out, "No path found.\n");
    }

}

void get_pos(FILE *in, int file_pos, short *x, short *y) {
    fseek(in, file_pos, SEEK_SET);
    int temp;
    fscanf(in, "%d (%hd %hd)", &temp, x, y);
}
