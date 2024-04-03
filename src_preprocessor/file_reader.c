#include "file_reader.h"

void get_maze_size(FILE *in, int *height, int *width, int start[], int end[]) {
    int h = 0, w = 0;
    char c;

    start[0] = start[1] = end[0] = end[1] = -1;

    while ((c=fgetc(in)) != EOF) {
        if (c == 'P') {
            start[0] = h;
            start[1] = w;
        }
        if (c == 'K') {
            end[0] = h;
            end[1] = w;
        }
        if (c == '\n') {
            h++;
            if (w > *width)
                *width = w;
            w = 0;
        } else {
            w++;
        }
    }
    *height = h;

    fseek(in, 0, SEEK_SET);
}

void read_file_to_mem(FILE *in, char **board, int height, int width) {
    int x = 0, y = 0;
    char c;
    while((c=fgetc(in)) != EOF) {
        if (c == '\n') {
            y++;
            x = 0;
        } else {
            board[y][x] = c;
            x++;
        }
    }
}

void print_board(char **board, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}
