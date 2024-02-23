#include "laby.h"

void lab_init(labyrinth *lab, int height, int width) {
    lab->board = malloc(height * sizeof(char*));

    for ( int i = 0; i < height; i++) {
        lab->board[i] = malloc(width * sizeof(char));
    }
}

void lab_fill(labyrinth *lab, FILE *in, int width) {
    fseek(in, 0, SEEK_SET);
    char buf;
    int i = 0, j = 0;
    
    while (fscanf(in, "%c", &buf) != EOF) {
        lab->board[i][j++] = buf;
        if (j == width) {
            j = 0;
            i++;
        }
        if (buf == 'P') {
            lab->pos_x = j;
            lab->pos_y = i;        
        }
    }

}

void lab_print(labyrinth *lab, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            printf("%c", lab->board[i][j]);
    }
}

void lab_free(labyrinth *lab, int height) {
    if (lab == NULL)
        return;

    for (int i = 0; i < height; i++) {
        free(lab->board[i]);
    }
    free(lab->board);
}