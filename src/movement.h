#ifndef _MOVEMENT_H
#define _MOVEMENT_H
#include "laby.h"
#include "solve.h"

void turn_left(MoveInstruction*);
void switch_turn_directon(MoveInstruction*);
void move_forward(labyrinth*, MoveInstruction*);

#endif