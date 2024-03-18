#ifndef _chunk_H        //chyba dobrze
#define _chunk_H

#include <stdio.h>
#include <stdlib.h>

typedef struct chunk {
    int pos_x;  //pozycje w pliku
    int pos_y;
    char cells[3][3];       //zmiana z ** na [][], nie trzeba malloca
} chunk;


//void chunk_init(chunk*);
void chunk_print(chunk*);
//void free_chunk(chunk*, int);
void get_chunk(chunk*, FILE*, const int, const int); //file or sqr????

#endif
