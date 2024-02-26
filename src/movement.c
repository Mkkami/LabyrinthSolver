#include "solve.h"
#include "laby.h"
#include "movement.h"

void turn_left(MoveInstruction *minst) {
    if (minst->move == FORWARD && minst->steps > 0) {
        print_steps(minst);
    }
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
    if (minst->steps == 3)
        switch_turn_directon(minst);
}

void switch_turn_directon(MoveInstruction *minst) {
    minst->dir = TURNRIGHT;
    minst->steps = 1;
}

void move_forward(labyrinth *lab, MoveInstruction *minst) {

    switch(minst->dir) {
        case NORTH:
            lab->pos_y--;
            break;
        case EAST:
            lab->pos_x--;
            break;
        case SOUTH:
            lab->pos_y++;
            break;
        case WEST:
            lab->pos_x++;
            break;
    }
    minst->steps++;
}
