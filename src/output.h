#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Position {
    short x;
    short y;
} Position;

void printPath(Position *ps, int*, FILE*, int, int);
Position *createPositionList(FILE*, int);


#endif