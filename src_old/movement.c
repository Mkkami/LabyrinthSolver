#include "solve.h"
#include "square.h"
#include "movement.h"

void turn_left(MoveInstruction *minst) {
    if (minst->move != TURNLEFT && minst->steps > 0) {
        print_steps(minst);
    }
    minst->move = TURNLEFT;
    switch(minst->dir) {
        case NORTH:
            minst->dir = WEST;
            break;
        case EAST:
            minst->dir = NORTH;
            break;
        case SOUTH:
            minst->dir = EAST;
            break;
        case WEST:
            minst->dir = SOUTH;
            break;
    }
    minst->steps++;
}

void turn_right(MoveInstruction *minst) {
    if (minst->move != TURNRIGHT && minst->steps > 0) {
        print_steps(minst);
    }
    minst->move = TURNRIGHT;
    switch(minst->dir) {
    case NORTH:
        minst->dir = EAST;
        break;
    case EAST:
        minst->dir = SOUTH;
        break;
    case SOUTH:
        minst->dir = WEST;
        break;
    case WEST:
        minst->dir = NORTH;
        break;
    }
    minst->steps++;
}

void move_forward(square *sqr, MoveInstruction *minst) {
    if (minst->move != FORWARD && minst->steps > 0) {
        print_steps(minst);
    }
    minst->move = FORWARD;
    switch(minst->dir) {
        case NORTH:
            sqr->pos_y--;
            break;
        case EAST:
            sqr->pos_x++;
            break;
        case SOUTH:
            sqr->pos_y++;
            break;
        case WEST:
            sqr->pos_x--;
            break;
    }
    minst->steps++;
}
