#include "laby.h"

void lab_init(labyrinth *lab) {
    lab->board = malloc(3 * sizeof(char*));

    for ( int i = 0; i < 3; i++) {
        lab->board[i] = malloc(3 * sizeof(char));
    }
}

void get_p_position(labyrinth *lab, FILE *in, int width) {
    fseek(in, 0, SEEK_SET);
    char buf;
    int i = 0, j = 0;
    
    while (fscanf(in, "%c", &buf) != EOF) {
        if (buf == 'P') {
            lab->pos_x = j;
            lab->pos_y = i;
            return;
        } else if (buf == '\n') {
            j = 0;
            i++;
        } else
            j++;
    }

}

void lab_print(labyrinth *lab) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%c", lab->board[i][j]);
        printf("\n");
    }
}

void lab_free(labyrinth *lab, int height) {
    if (lab == NULL)
        return;

    for (int i = 0; i < 3; i++) {
        free(lab->board[i]);
    }
    free(lab->board);
}

void get_square(labyrinth *lab, FILE *in, int height, int width) {
    //int index = (lab->pos_y * (width + 1)) + lab->pos_x;
    int start_x = lab->pos_x - 1;
    int start_y = lab->pos_y - 1;
    int index;

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            int x = start_x + j;
            int y = start_y + i;

            if (x < 0 || y < 0 || x >= width || y >= height ) {
                lab->board[i][j] = 'X';

            } else {
                index =  (y * (width + 1)) + x;
                fseek(in, index, SEEK_SET);
                lab->board[i][j] = fgetc(in);
            }
        }
    }
}