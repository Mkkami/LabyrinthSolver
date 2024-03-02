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
void get_size(FILE *in, int *height, int *width) {
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
    h++;
    *height = h;

    fseek(in, 0, SEEK_SET);
}

void get_p_position(square *sqr, FILE *in, int width) {
    fseek(in, 0, SEEK_SET);
    char buf;
    int i = 0, j = 0;
    
    while (fscanf(in, "%c", &buf) != EOF) {
        if (buf == 'P') {
            sqr->pos_x = j;
            sqr->pos_y = i;
            return;
        } else if (buf == '\n') {
            j = 0;
            i++;
        } else
            j++;
    }

}

void change_to_elem(square *sqr, FILE *in, const int width, const char element) {
    int index =  ((sqr->pos_y) * (width + 1)) + sqr->pos_x;
    fseek(in, index, SEEK_SET);
    fputc(element, in);
    // fseek(in, 0, SEEK_SET);
}