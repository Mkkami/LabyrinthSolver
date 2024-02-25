#include "solve.h"


void print_steps(MoveInstruction *minst) {
    switch(minst->move) {
        case START:
            printf("START\n");
            break;
        case FORWARD:
            printf("FORWARD %d\n", minst->steps);
            break;
        case TURNRIGHT:
            printf("TURNRIGHT %d\n", minst->steps);
            break;
        case TURNLEFT:
            printf("TURNLEFT %d\n", minst->steps);
            break;
        case STOP:
            printf("STOP\n");
            break;
    }
    minst->steps = 0;
}

void init_direction(labyrinth *lab, MoveInstruction *minst, int height, int width) {
    if (lab->pos_x == 0)
        minst->dir = EAST;
    if (lab->pos_x == width)
        minst->dir = WEST;
    if (lab->pos_y == 0)
        minst->dir = SOUTH;
    if (lab->pos_y == height)
        minst->dir = NORTH;
}
