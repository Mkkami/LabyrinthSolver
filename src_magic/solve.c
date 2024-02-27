#include "solve.h"
#define MID 1

void initiate(square *sqr, MoveInstruction *minst, FILE *out, const int height, const int width) {
    get_p_position(sqr, out, width);
    get_square(sqr, out, height, width);
    init_direction(sqr, minst, height, width);
}

void init_direction(square *sqr, MoveInstruction *minst, const int height, const int width) {
    if (sqr->pos_x == 1)
        minst->dir = EAST;
    if (sqr->pos_x == width)
        minst->dir = WEST;
    if (sqr->pos_y == 1)
        minst->dir = SOUTH;
    if (sqr->pos_y == height)
        minst->dir = NORTH;
}

int check_right_elem(square *sqr, MoveInstruction *minst, const char element) {
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
    return sqr->board[y][x] == element;
}

int end_reached(square *sqr, MoveInstruction *minst) {
    if (sqr->board[MID][MID] == 'K') {
        return 1;
    }
    return 0;
}

int check_forward(square *sqr, MoveInstruction *minst, const char element) {
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
    return (sqr->board[y][x] == element);
}

int check_K(square *sqr, MoveInstruction *minst) {

    if (sqr->board[MID-1][MID] == 'K') return 1;
    if (sqr->board[MID+1][MID] == 'K') return 1;
    if (sqr->board[MID][MID-1] == 'K') return 1;
    if (sqr->board[MID][MID+1] == 'K') return 1;
    return 0;
}

int check_left_elem(square *sqr, MoveInstruction *minst, const char element) {
    int x = MID;
    int y = MID;
    
    switch(minst->dir) {
        case NORTH:
            x--;
            break;
        case EAST:
            y--;
            break;
        case SOUTH:
            x++;
            break;
        case WEST:
            y++;
            break;
    }
    return sqr->board[y][x] == element;
}