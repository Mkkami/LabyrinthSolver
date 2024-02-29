#include "solve.h"
#define MID 1

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

void init_direction(square *sqr, MoveInstruction *minst, int height, int width) {
    if (sqr->pos_x == 0)
        minst->dir = EAST;
    if (sqr->pos_x == width)
        minst->dir = WEST;
    if (sqr->pos_y == 0)
        minst->dir = SOUTH;
    if (sqr->pos_y == height)
        minst->dir = NORTH;
}

int check_right_x(square *sqr, MoveInstruction *minst) {
    int x = MID;
    int y = MID;
    
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
    return sqr->board[y][x] == 'X';
}

int end_reached(square *sqr, MoveInstruction *minst) {
    if (sqr->board[MID][MID] == 'K') {
        return 1;
    }
    return 0;
}

int check_forward_x(square *sqr, MoveInstruction *minst) {
    int x = MID;
    int y = MID;

    switch(minst->dir) {
        case NORTH:
            y--;
            break;
        case EAST:
            x++;
            break;
        case SOUTH:
            y++;
            break;
        case WEST:
            x--;
            break;
    }
    return (sqr->board[y][x] == 'X');
}

int check_K(square *sqr, MoveInstruction *minst) {

    if (sqr->board[MID-1][MID] == 'K') return 1;
    if (sqr->board[MID+1][MID] == 'K') return 1;
    if (sqr->board[MID][MID-1] == 'K') return 1;
    if (sqr->board[MID][MID+1] == 'K') return 1;
    return 0;
}

int check_R(square *sqr, MoveInstruction *minst) {
    //checks if there's T from left to right - it is the shortest path
}