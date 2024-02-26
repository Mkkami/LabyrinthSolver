#include "solve.h"


void print_steps(MoveInstruction *minst) {
    switch(minst->move) {
        case START:
            printf("START");
            break;
        case FORWARD:
            printf("FORWARD %d", minst->steps);
            break;
        case TURNRIGHT:
            printf("TURNRIGHT %d", minst->steps);
            break;
        case TURNLEFT:
            printf("TURNLEFT %d", minst->steps);
            break;
        case STOP:
            printf("STOP");
            break;
    }
    printf("\n");
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

int check_right_x(labyrinth *lab, MoveInstruction *minst) {
    int x = 2;
    int y = 2;
    
    switch(minst->dir) {
        case NORTH:
            x++;
            break;
        case EAST:
            y++;
            break;
        case SOUTH:
            x--;
            break;
        case WEST:
            y--;
            break;
    }
    return lab->board[y][x] == 'X';
}