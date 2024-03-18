#ifndef _MOVEMENT_H         //chyba dobrze
#define _MOVEMENT_H

//#include "structures.h"
//ONLY FOR MOVEMENT OPERATIONS

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

void turn_left(enum Direction*);
void turn_right(enum Direction*);
void move_forward(int*, int*, enum Direction);
void turn_back(enum Direction*);

void print_dir(enum Direction);

#endif
