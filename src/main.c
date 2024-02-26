#include <stdio.h>
#include <stdlib.h>
#include "laby.h"
#include "file.h"
#include "solve.h"
#include "movement.h"

int main(int argc, char **argv) {
    FILE *in = NULL;
    int height = 0;
    int width = 0;

    labyrinth *lab = malloc(sizeof(labyrinth));
    MoveInstruction *minst = malloc(sizeof(MoveInstruction));
    //error checks
    if (lab == NULL || minst == NULL) {
        fprintf(stderr, "%s: Nie mozna alokowac pamieci dla lab\n", argv[0]);
        return 1;
    }

    if (argc > 1) {
        in = fopen(argv[1], "r");
    } else {
        fprintf(stderr, "%s: Brak podanego pliku wejsciowego\n", argv[0]);
        free(lab);
        free(minst);
        return 1;
    }

    if (in == NULL) { 
        fprintf(stderr, "%s: Nie mozna czytac pliku %s\n", argv[0], argv[1]);
        free(lab);
        free(minst);
        return 2;
    }
    //
    
    //initialize
    get_size(in, &height, &width);

    lab_init(lab);
    get_p_position(lab, in, width);
    get_square(lab, in, height, width);

    init_direction(lab, minst, height, width);
    //

    //run
    while (!end_reached(lab, minst)) {
        if (!check_K(lab, minst)) {
            if (check_right_x(lab, minst)) {
                if (!check_forward_x(lab, minst)) {
                    move_forward(lab, minst);
                    get_square(lab, in, height, width);
                } else {
                    turn_left(minst);
                }

            } else {
                turn_right(minst);
                move_forward(lab, minst);
                get_square(lab, in, height, width);
            }
        } else {
            printf("K found!!!\n");
            break;
        }
    }
    //

    //free memory
    fclose(in);
    lab_free(lab, height);
    free(lab);
    free(minst);
    //

    return 0;
}