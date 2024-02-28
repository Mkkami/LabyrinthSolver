#include "solve.h"

void initiate(square *sqr, MoveInstruction *minst, FILE *out, const int height, const int width) {
    get_p_position(sqr, out, width);
    get_square(sqr, out, height, width);
    init_direction(sqr, minst, height, width);
}

void init_direction(square *sqr, MoveInstruction *minst, const int height, const int width) {
    if (sqr->pos_x == 1)
        minst->dir = EAST;
    if (sqr->pos_x == width)
        minst->dir = WEST;
    if (sqr->pos_y == 1)
        minst->dir = SOUTH;
    if (sqr->pos_y == height)
        minst->dir = NORTH;
}

void fill_dead_end(square *sqr, MoveInstruction *minst, FILE *filename, const int height, const int width) {
    int filling_process = 0;

    while (!end_reached(sqr, minst)) {
        // print_dir(minst);
        // printf(" %d, %d\n", sqr->pos_x, sqr->pos_y);
        if (check_K(sqr, minst)) {
            printf("K found!!!\n");
            break;

        } else if (check_dead_end(sqr) && sqr->board[1][1] != 'P') {
            change_to_elem(sqr, filename, width, 'X');
            if (filling_process == 0) turn_back(minst);
            filling_process = 1;

        } else if (check_right_elem(sqr, minst, ' ')) {
            turn_right(minst);
            filling_process = 0;

        } else if (check_forward(sqr, minst, ' ')) {
            filling_process = 0;

        } else {
            filling_process = 0;
            turn_left(minst);
        }
        move_forward(sqr, minst);
        get_square(sqr, filename, height, width);
        sqr_print(sqr);
    }
}