#ifndef _SOLVE_H
#define _SOLVE_H
#include "laby.h"

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
void init_direction(labyrinth*, MoveInstruction*, int, int);

#endif