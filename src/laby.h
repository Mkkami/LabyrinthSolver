#ifndef _LABY_H
#define _LABY_H
#include <stdio.h>
#include <stdlib.h>

typedef struct labyrinth {
    int pos_x;
    int pos_y;
    char **board;
} labyrinth;


void lab_init(labyrinth*, int, int);
void lab_fill(labyrinth*, FILE*, int);
void lab_print(labyrinth*, int, int);
void lab_free(labyrinth*, int);

#endif