#include "movement.h"

void turn_left(enum Direction* dir) {
    switch(*dir) {
        case NORTH:
            *dir = WEST;
            break;
        case EAST:
            *dir = NORTH;
            break;
        case SOUTH:
            *dir = EAST;
            break;
        case WEST:
            *dir = SOUTH;
            break;
    }
}

void turn_right(enum Direction* dir) {
    switch(*dir) {
    case NORTH:
        *dir = EAST;
        break;
    case EAST:
        *dir = SOUTH;
        break;
    case SOUTH:
        *dir = WEST;
        break;
    case WEST:
        *dir = NORTH;
        break;
    }
}

void move_forward(int *pos_x, int *pos_y, enum Direction dir) {
    switch(dir) {
        case NORTH:
            (*pos_y)--;
            break;
        case EAST:
            (*pos_x)++;
            break;
        case SOUTH:
            (*pos_y)++;
            break;
        case WEST:
            (*pos_x)--;
            break;
    }
}

void turn_back(enum Direction* dir) {
    switch(*dir) {
    case NORTH:
        *dir = SOUTH;
        break;
    case EAST:
        *dir = WEST;
        break;
    case SOUTH:
        *dir = NORTH;
        break;
    case WEST:
        *dir = EAST;
        break;
    }
}
#include <stdio.h>
void print_dir(enum Direction dir) {
    switch(dir) {
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