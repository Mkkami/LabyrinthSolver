#ifndef _MAZETOGRAPH_H
#define _MAZETOGRAPH_H

#include <stdio.h>

enum Direction {
    UP,
    LEFT,
    RIGHT,
    DOWN
};

void place_node(char**, int, int);
int placer(char **, int , int );
int check_direction(char **, enum Direction , int , int , int , int );
void connecter(char **, int**, int , int , int , FILE *);
void ID_fill(char **, int **, int , int );

#endif