#ifndef _SOLVE_H
#define _SOLVE_H

#include <stdio.h> //FILE
#include "file.h" //get_p_position, change_to_elem, 
#include "square.h" //get_square

#include "movement.h"
#include "checks.h"

#include "structures.h"

//FOR SOLVING THE MAZE

void initiate(square*, MoveInstruction*, FILE*, const int, const int);
void init_direction(square*, MoveInstruction*, const int, const int);
void fill_dead_end(square *, MoveInstruction *, FILE *, const int, const int);

#endif