#include "file.h"

void get_size(FILE *in, int *height, int *width) {
    int h = 0, w = 0;
    char c;
    int windows_file = 0;

    while (fscanf(in, "%c", &c) != EOF) {
        if (c == '\n') {
            h++;
            if (w > *width)
                *width = w;
            w = 0;
        } else {
            w++;
            if (c == '\r')
                windows_file = 1;
        }
    }
    h++;
    *height = h;

    if (windows_file) 
        (*width)--;
    
    fseek(in, 0, SEEK_SET);
}