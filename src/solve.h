#ifndef _SOLVE_H
#define _SOLVE_H

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

typedef struct {
    int steps;
    enum dir Direction;
    enum move Movement;
};

#endif