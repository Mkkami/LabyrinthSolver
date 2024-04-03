#ifndef _READER_H
#define _READER_H

#include <stdio.h>

void get_maze_size(FILE *in, int*, int*, int[], int[]);
void read_file_to_mem(FILE *in, char**, int, int);
void print_board(char **, int, int);


#endif