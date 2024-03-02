#ifndef _FILE_H
#define _FILE_H

#include "structures.h"

//ONLY FOR OPERATIONS ON FILE

void print_file(const char*);
void get_size(FILE*, int *, int *);
void get_p_position(square*, FILE*, int);
void change_to_elem(square *, FILE*, const int, const char);

#endif
