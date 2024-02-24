#ifndef _LABY_H
#define _LABY_H
#include <stdio.h>
#include <stdlib.h>

typedef struct labyrinth {
    int pos_x;
    int pos_y;
    char **board;
} labyrinth;


void lab_init(labyrinth*);
void get_p_position(labyrinth*, FILE*, int);
void lab_print(labyrinth*);
void lab_free(labyrinth*, int);
void get_square(labyrinth*, FILE*, int, int);

#endif