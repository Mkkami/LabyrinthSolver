#include "solve.h"
#include "chunk.h"
#include "movement.h"
#include "file.h"

void initiate(chunk *ck, enum Direction *dir, FILE *out, const int height, const int width) {
    //get_start_position(ck, out, width);
    get_chunk(ck, out, height, width);
    init_direction(ck, dir, height, width);
}

void init_direction(chunk *ck, enum Direction *dir, const int height, const int width) {
    if (ck->pos_x == 0)
        *dir = EAST;
    if (ck->pos_x == width)
        *dir = WEST;
    if (ck->pos_y == 0)
        *dir = SOUTH;
    if (ck->pos_y == height)
        *dir = NORTH;
}

int fill_dead_end(chunk *ck, enum Direction *dir, FILE *filename, const int height, const int width) {
    int filling_process = 0;    //sprawdza czy już wypełnia pola, aby nie obrócić się drugi raz
    int ile = 0;

    while (!end_reached(ck, *dir)) {
        if (adjacent_to_end(ck, *dir)) {
            printf("K found!!!\n");
            break;

        } else if (check_dead_end(ck) && ck->cells[1][1] != 'P') {

            change_to_cell(ck->pos_x, ck->pos_y, filename, width, 'X');
            ile++;
            if (filling_process == 0) turn_back(dir);
            filling_process = 1;

            if (check_forward(ck, *dir, 'X')) {       //musi być ten warunek bo inaczej to pójdzie do przodu nawet jak jest 'X'
                if (check_right_cell(ck, *dir, ' '))
                    turn_right(dir);
                else
                    turn_left(dir);
            }
        
        //  trzyma się prawej strony po prostu
        } else if (check_right_cell(ck, *dir, ' ')) {
            turn_right(dir);
            filling_process = 0;

        } else if (check_forward(ck, *dir, ' ')) {
            filling_process = 0;

        } else if (check_left_cell(ck, *dir, ' ')) {
            turn_left(dir);
            filling_process = 0;
        }
        move_forward(&(ck->pos_x), &(ck->pos_y), *dir);
        get_chunk(ck, filename, height, width);
    }
    return ile;
}

// void print_steps(chunk *ck, enum Direction dir, FILE *filename, )