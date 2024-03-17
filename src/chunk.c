#include "chunk.h"
#define CHUNK_SIZE 3

// void ck_init(chunk *ck) {
//     ck->cells = malloc(CHUNK_SIZE * sizeof(char*));

//     for ( int i = 0; i < CHUNK_SIZE; i++) {
//         ck->cells[i] = malloc(CHUNK_SIZE * sizeof(char));
//     }
// }

void chunk_print(chunk *ck) {
    for (int i = 0; i < CHUNK_SIZE; i++) {
        for (int j = 0; j < CHUNK_SIZE; j++)
            printf("%c", ck->cells[i][j]);
        printf("\n");
    }
}

// void free_chunk(chunk *ck, int height) {
//     if (ck == NULL)
//         return;

//     for (int i = 0; i < CHUNK_SIZE; i++) {
//         free(ck->cells[i]);
//     }
//     free(ck->cells);
// }

void get_chunk(chunk *ck, FILE *in, const int height, const int width) {

    int start_x = ck->pos_x - 1;
    int start_y = ck->pos_y - 1;
    int index;

    for (int i = 0; i < CHUNK_SIZE; i++) {
        for (int j = 0; j < CHUNK_SIZE; j++) {
            int x = start_x + j;
            int y = start_y + i;
            
            if (x < 0 || x >= width || y < 0 || y >= height) {
                ck->cells[i][j] = 'X';
            } else {
                index =  ((y) * (width + 1)) + x;
                fseek(in, index, SEEK_SET);
                ck->cells[i][j] = fgetc(in);
            }
        }
    }
}
