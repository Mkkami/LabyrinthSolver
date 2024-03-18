#ifndef _SOLVE_H
#define _SOLVE_H

#include <stdio.h> //FILE
#include "file_edit.h" //get_p_position, change_to_elem, 
#include "chunk.h" //get_square

#include "movement.h"
#include "checks.h"

//#include "structures.h"



//FOR SOLVING THE MAZE

void initiate(chunk*, enum Direction*, FILE*, const int, const int);
void init_direction(chunk*, enum Direction*, const int, const int);
int fill_dead_end(chunk *, enum Direction*, FILE *, const int, const int);
void print_steps(chunk*, enum Direction, FILE*, const int, const int);

#endif