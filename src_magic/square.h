#ifndef _SQUARE_H
#define _SQUARE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct square {
    int pos_x;
    int pos_y;
    char **board;
} square;


void sqr_init(square*);
void get_p_position(square*, FILE*, int);
void sqr_print(square*);
void sqr_free(square*, int);
void get_square(square*, FILE*, int, int);

#endif