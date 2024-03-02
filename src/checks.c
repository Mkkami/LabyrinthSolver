#include "checks.h"

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

int check_dead_end(square *sqr) {
    int count = 0;
    if (sqr->board[0][1] == 'X') count++;
    if (sqr->board[1][0] == 'X') count++;
    if (sqr->board[2][1] == 'X') count++;
    if (sqr->board[1][2] == 'X') count++;
    if (count == 3) 
        return 1;
    return 0;
}