#include "checks.h"

int check_right_cell(chunk *ck, enum Direction dir, const char element) {
    int x = MID;
    int y = MID;
    
    switch(dir) {
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
    return ck->cells[y][x] == element;
}

int end_reached(chunk *ck, enum Direction dir) {
    if (ck->cells[MID][MID] == 'K') {
        return 1;
    }
    return 0;
}

int check_forward(chunk *ck, enum Direction dir, const char element) {
    int x = MID;
    int y = MID;

    switch(dir) {
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
    return (ck->cells[y][x] == element);
}

int adjacent_to_end(chunk *ck, enum Direction) {

    if (ck->cells[MID-1][MID] == 'K') return 1;
    if (ck->cells[MID+1][MID] == 'K') return 1;
    if (ck->cells[MID][MID-1] == 'K') return 1;
    if (ck->cells[MID][MID+1] == 'K') return 1;
    return 0;
}

int check_left_cell(chunk *ck, enum Direction dir, const char element) {
    int x = MID;
    int y = MID;
    
    switch(dir) {
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
    return ck->cells[y][x] == element;
}

int check_dead_end(chunk *ck) {
    int count = 0;
    if (ck->cells[0][1] == 'X') count++;
    if (ck->cells[1][0] == 'X') count++;
    if (ck->cells[2][1] == 'X') count++;
    if (ck->cells[1][2] == 'X') count++;
    if (count == 3) 
        return 1;
    return 0;
}