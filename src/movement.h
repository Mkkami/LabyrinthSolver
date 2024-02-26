#ifndef _MOVEMENT_H
#define _MOVEMENT_H
#include "laby.h"
#include "solve.h"

void turn_left(MoveInstruction*);
void turn_right(MoveInstruction*);
void move_forward(labyrinth*, MoveInstruction*);

#endif