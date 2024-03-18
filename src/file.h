#ifndef _FILE_H
#define _FILE_H

//#include "structures.h"

//ONLY FOR OPERATIONS ON FILE

void print_file(const char*);
void get_maze_size(FILE*, int *, int *);
void get_start_position( FILE*, int, int*, int*);
//void change_to_cell(chunk *, FILE*, const int, const char);    //move to file_edit
void copy_file(FILE*, FILE*);

#endif
