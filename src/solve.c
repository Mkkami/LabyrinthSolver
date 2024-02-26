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
    return lab->board[y][x] == 'X';
}

int end_reached(labyrinth *lab, MoveInstruction *minst) {
    if (lab->board[MID][MID] == 'K') {
        return 1;
    }
    return 0;
}

int check_forward_x(labyrinth *lab, MoveInstruction *minst) {
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
    return (lab->board[y][x] == 'X');
}

int check_K(labyrinth *lab, MoveInstruction *minst) {

    if (lab->board[MID-1][MID] == 'K') return 1;
    if (lab->board[MID+1][MID] == 'K') return 1;
    if (lab->board[MID][MID-1] == 'K') return 1;
    if (lab->board[MID][MID+1] == 'K') return 1;
    return 0;
}