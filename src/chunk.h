#ifndef _chunk_H
#define _chunk_H

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

//ONLY FOR OPERATIONS ON chunk

//void chunk_init(chunk*);
void chunk_print(chunk*);
//void free_chunk(chunk*, int);
void get_chunk(chunk*, FILE*, const int, const int); //file or sqr????

#endif
