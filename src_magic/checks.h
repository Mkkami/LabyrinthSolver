#ifndef _CHECKS_H
#define _CHECKS_H

#include "structures.h"

//ONLY FOR CHECKING ELEMENTS IN THE SQUARE

int check_right_elem(square*, MoveInstruction*, const char);
int end_reached(square*, MoveInstruction*);
int check_forward(square*, MoveInstruction*, const char);
int check_K(square*, MoveInstruction*);
int check_left_elem(square*, MoveInstruction*, const char);
int check_dead_end(square*);

#endif