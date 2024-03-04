#ifndef _ERRORS_H
#define _ERRORS_H

#include <stdio.h>

int check_input_err(const int, char**); 
int check_err(FILE*, FILE*, const int, const int, char**);


#endif