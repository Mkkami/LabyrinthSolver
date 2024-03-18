#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void print_file(const char *filename) {
    FILE *out = fopen(filename, "r");
    char ch;

    while ((ch = fgetc(out)) != EOF) {
        putchar(ch);
    }

    fclose(out);
}

void get_maze_size(FILE *in, int *height, int *width) {
    int h = 0, w = 0;
    char c;

    while (fscanf(in, "%c", &c) != EOF) {
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

void get_start_position(FILE *in, int width, int *start_x, int *start_y) {
    fseek(in, 0, SEEK_SET);
    char buf;
    int i = 0, j = 0;
    
    while (fscanf(in, "%c", &buf) != EOF) {
        if (buf == 'P') {
            *start_x = j;
            *start_y = i;
            return;
        } else if (buf == '\n') {
            j = 0;
            i++;
        } else
            j++;
    }

}



void copy_file(FILE *in, FILE *copy) {
    fseek(in, 0, SEEK_SET);
    char c;

    while ((c=fgetc(in)) != EOF) {
        fputc(c, copy);
    }
}