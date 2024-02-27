#ifndef _FILE_H
#define _FILE_H
#include "square.h"

void print_file(const char*);
void get_size(FILE*, int *, int *);
void change_to_elem(square *, FILE*, const int, const char);

#endif