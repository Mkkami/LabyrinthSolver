#ifndef _MOVEMENT_H
#define _MOVEMENT_H

#include "structures.h"

//ONLY FOR MOVEMENT OPERATIONS

void turn_left(MoveInstruction*);
void turn_right(MoveInstruction*);
void move_forward(square*, MoveInstruction*);
void turn_back(MoveInstruction*);

void print_dir(MoveInstruction*);

#endif
