#include "file_edit.h"

void change_to_cell(int x, int y, FILE *in, const int width, const char element) {
    int index =  ((y) * (width + 1)) + x;
    fseek(in, index, SEEK_SET);
    fputc(element, in);
    // fseek(in, 0, SEEK_SET);
}