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

void change_to_elem(square *sqr, FILE *in, const int width, const char element) {
    int index =  ((sqr->pos_y) * (width + 1)) + sqr->pos_x;
    fseek(in, index, SEEK_SET);
    fputc(element, in);
}

void mark_shortest_path(square *sqr, MoveInstruction *minst, FILE *out, const int height, const int width) {
    while (!end_reached(sqr, minst)) {
        if (!check_K(sqr, minst)) {
            if (check_left_elem(sqr, minst, '+')) {
                turn_left(minst);
                move_forward(sqr, minst);
                get_square(sqr, out, height, width);
                change_to_elem(sqr, out, width, 'o'); 
            } else if (check_forward(sqr, minst, '+')) {
                    move_forward(sqr, minst);
                    change_to_elem(sqr, out, width, 'o');
                    get_square(sqr, out, height, width);
                    
            } else {
                turn_right(minst);
                move_forward(sqr, minst);
                get_square(sqr, out, height, width);
                change_to_elem(sqr, out, width, 'o');
            }
        } else {
            printf("K found program end\n");
            break;
        }
    }
}