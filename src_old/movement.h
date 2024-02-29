#ifndef _MOVEMENT_H
#define _MOVEMENT_H
#include "square.h"
#include "solve.h"

void turn_left(MoveInstruction*);
void turn_right(MoveInstruction*);
void move_forward(square*, MoveInstruction*);

#endif