#ifndef _SOLVE_H
#define _SOLVE_H
#include "square.h"

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

typedef struct MoveInstruction {
    enum Direction dir;
} MoveInstruction;

void init_direction(square*, MoveInstruction*, const int, const int);
int check_right_elem(square*, MoveInstruction*, const char);
int end_reached(square*, MoveInstruction*);
int check_forward(square*, MoveInstruction*, const char);
int check_K(square*, MoveInstruction*);
int check_left_elem(square*, MoveInstruction*, const char);

#endif