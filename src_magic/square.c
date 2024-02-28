#include "square.h"
#define SQUARE_SIZE 3

void sqr_init(square *sqr) {
    sqr->board = malloc(SQUARE_SIZE * sizeof(char*));

    for ( int i = 0; i < SQUARE_SIZE; i++) {
        sqr->board[i] = malloc(SQUARE_SIZE * sizeof(char));
    }
}

void sqr_print(square *sqr) {
    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++)
            printf("%c", sqr->board[i][j]);
        printf("\n");
    }
}

void sqr_free(square *sqr, int height) {
    if (sqr == NULL)
        return;

    for (int i = 0; i < SQUARE_SIZE; i++) {
        free(sqr->board[i]);
    }
    free(sqr->board);
}

void get_square(square *sqr, FILE *in, int height, int width) {
    //int index = (sqr->pos_y * (width + 1)) + sqr->pos_x;
    int start_x = sqr->pos_x - 1;
    int start_y = sqr->pos_y - 1;
    int index;

    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++) {
            int x = start_x + j;
            int y = start_y + i;

            index =  ((y) * (width + 1)) + x;
            fseek(in, index, SEEK_SET);
            sqr->board[i][j] = fgetc(in);
        }
    }
}
