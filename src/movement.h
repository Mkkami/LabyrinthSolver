#ifndef _MOVEMENT_H
#define _MOVEMENT_H
#include "laby.h"
#include "solve.h"

void turn_left(MoveInstruction *minst);
void switch_turn_directon(MoveInstruction *minst);
void move_forward(labyrinth *lab, MoveInstruction *minst);

#endif