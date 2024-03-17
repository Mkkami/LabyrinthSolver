#ifndef _CHECKS_H
#define _CHECKS_H

#include "structures.h"

//ONLY FOR CHECKING ELEMENTS IN THE chunk

int check_right_cell(chunk*, enum Direction, const char);
int end_reached(chunk*, enum Direction);
int check_forward(chunk*, enum Direction, const char);
int adjacent_to_end(chunk*, enum Direction);
int check_left_cell(chunk*, enum Direction, const char);
int check_dead_end(chunk*);

#endif