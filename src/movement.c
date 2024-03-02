#include "movement.h"

void turn_left(MoveInstruction *minst) {
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
}

void turn_right(MoveInstruction *minst) {
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
}

void move_forward(square *sqr, MoveInstruction *minst) {
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
}

void turn_back(MoveInstruction *minst) {
    switch(minst->dir) {
    case NORTH:
        minst->dir = SOUTH;
        break;
    case EAST:
        minst->dir = WEST;
        break;
    case SOUTH:
        minst->dir = NORTH;
        break;
    case WEST:
        minst->dir = EAST;
        break;
    }
}
#include <stdio.h>
void print_dir(MoveInstruction *minst) {
    switch(minst->dir) {
    case NORTH:
        printf("NORTH");
        break;
    case EAST:
        printf("EAST");
        break;
    case SOUTH:
        printf("SOUTH");
        break;
    case WEST:
        printf("WEST");
        break;
    }
}