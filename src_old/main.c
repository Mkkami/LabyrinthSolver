#include <stdio.h>
#include <stdlib.h>
#include "square.h"
#include "file.h"
#include "solve.h"
#include "movement.h"

int main(int argc, char **argv) {
    FILE *in = NULL;
    int height = 0;
    int width = 0;

    square *sqr = malloc(sizeof(square));
    MoveInstruction *minst = malloc(sizeof(MoveInstruction));
    //error checks
    if (sqr == NULL || minst == NULL) {
        fprintf(stderr, "%s: Nie mozna zaallokowac pamieci\n", argv[0]);
        return 1;
    }

    if (argc > 1) {
        in = fopen(argv[1], "r");
    } else {
        fprintf(stderr, "%s: Brak podanego pliku wejsciowego\n", argv[0]);
        free(sqr);
        free(minst);
        return 1;
    }

    if (in == NULL) { 
        fprintf(stderr, "%s: Nie mozna czytac pliku %s\n", argv[0], argv[1]);
        free(sqr);
        free(minst);
        return 2;
    }
    //
    
    //initialize
    get_size(in, &height, &width);

    sqr_init(sqr);
    get_p_position(sqr, in, width);
    get_square(sqr, in, height, width);

    init_direction(sqr, minst, height, width);
    //

    //run
    while (!end_reached(sqr, minst)) {
        if (!check_K(sqr, minst)) {
            if (check_right_x(sqr, minst)) {
                if (!check_forward_x(sqr, minst)) {
                    move_forward(sqr, minst);
                    get_square(sqr, in, height, width);
                } else {
                    turn_left(minst);
                }

            } else {
                turn_right(minst);
                move_forward(sqr, minst);
                get_square(sqr, in, height, width);
            }
        } else {
            printf("K found!!!\n");
            break;
        }
    }
    //

    //free memory
    fclose(in);
    sqr_free(sqr, height);
    free(sqr);
    free(minst);
    //

    return 0;
}