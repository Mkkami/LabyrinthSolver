#ifndef _SOLVE_H
#define _SOLVE_H
#include "square.h"

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

enum Movement {
    START,
    FORWARD,
    STOP,
    TURNRIGHT,
    TURNLEFT,
};

typedef struct MoveInstruction {
    int steps;
    enum Direction dir;
    enum Movement move;
} MoveInstruction;

void print_steps(MoveInstruction*);
void init_direction(square*, MoveInstruction*, int, int);
int check_right_x(square*, MoveInstruction*);
int end_reached(square*, MoveInstruction*);
int check_forward_x(square*, MoveInstruction*);
int check_K(square*, MoveInstruction*);

#endif