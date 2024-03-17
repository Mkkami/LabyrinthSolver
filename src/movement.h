#ifndef _MOVEMENT_H
#define _MOVEMENT_H

#include "structures.h"

//ONLY FOR MOVEMENT OPERATIONS

void turn_left(enum Direction*);
void turn_right(enum Direction*);
void move_forward(chunk*, enum Direction);
void turn_back(enum Direction*);

void print_dir(enum Direction);

#endif
