#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#define MID 1

//ALL STRUCTURES USED IN A PROGRAM

typedef struct square {
    int pos_x;
    int pos_y;
    char **board;
} square;

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

typedef struct MoveInstruction {
    enum Direction dir;
} MoveInstruction;

typedef enum ErrorCode {
    NO_ERROR,
    FILE_OPEN_ERROR,
    FILE_READ_ERROR,
    FILE_WRITE_ERROR,
    MEMORY_ALLOCATION_ERROR,
    INVALID_ARGUMENT_ERROR,
    OTHER_ERROR,
} ErrorCode;

#endif