#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#define MID 1

//ALL STRUCTURES USED IN A PROGRAM

typedef struct chunk {
    int pos_x;  //pozycje w pliku
    int pos_y;
    char cells[3][3];       //zmiana z ** na [][], nie trzeba malloca
} chunk;

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

// typedef struct MoveInstruction {        po prostu zmień na zwykłą zmienną zamiast strukture robić
//     enum Direction dir;
// } MoveInstruction;


#endif