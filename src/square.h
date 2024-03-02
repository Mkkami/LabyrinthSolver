#ifndef _SQUARE_H
#define _SQUARE_H

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

//ONLY FOR OPERATIONS ON SQUARE

void sqr_init(square*);
void sqr_print(square*);
void sqr_free(square*, int);
void get_square(square*, FILE*, int, int); //file or sqr????

#endif
