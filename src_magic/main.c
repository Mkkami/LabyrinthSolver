#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "solve.h"
#include "square.h"
#include "movement.h"

int main(int argc, char **argv) {
    FILE *in, *out;
    char elem;
    int height, width;
    square *sqr = malloc(sizeof(square));
    MoveInstruction *minst = malloc(sizeof(MoveInstruction));

    in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku %s\n", argv[1]);
        return 1;
    }

    out = fopen("TEMP/plik.maze", "w+");
    if (out == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku plik.maze\n");
        fclose(in);
        return 2;
    }
    get_size(in, &height, &width);

    //wypełnij plik
    //fprintf(out, "%d %d\n", height, width);
    while ((elem = fgetc(in)) != EOF) {
        fputc(elem, out);
    }
    //
    fclose(in);
    //
    sqr_init(sqr);
    get_p_position(sqr, out, width);
    get_square(sqr, out, height, width);

    init_direction(sqr, minst, height, width);
    //zmien kolor
    while (!end_reached(sqr, minst)) {
        if (!check_K(sqr, minst)) {
            if (check_right_elem(sqr, minst, 'X')) {
                if (!check_forward(sqr, minst, 'X')) {
                    move_forward(sqr, minst);
                    get_square(sqr, out, height, width);
                    change_to_elem(sqr, out, width, '+');
                } else {
                    turn_left(minst);
                }

            } else {
                turn_right(minst);
                move_forward(sqr, minst);
                get_square(sqr, out, height, width);
                change_to_elem(sqr, out, width, '+');
            }
        } else {
            printf("K found!!!\n");
            break;
        }
    }
    get_p_position(sqr, out, width);
    get_square(sqr, out, height, width);
    sqr_print(sqr);
    printf("\n");

    init_direction(sqr, minst, height, width);
    fseek(out, 0, SEEK_SET);

    while (!end_reached(sqr, minst)) {
        if (!check_K(sqr, minst)) {
            if (check_left_elem(sqr, minst, '+')) {
                turn_left(minst);
                move_forward(sqr, minst);
                get_square(sqr, out, height, width);
                change_to_elem(sqr, out, width, 'o'); 
            } else if (check_forward(sqr, minst, '+')) {
                    move_forward(sqr, minst);
                    change_to_elem(sqr, out, width, 'o');
                    get_square(sqr, out, height, width);
                    
            } else {
                turn_right(minst);
                move_forward(sqr, minst);
                get_square(sqr, out, height, width);
                change_to_elem(sqr, out, width, 'o');
            }
        } else {
            printf("K found program end\n");
            break;
        }
    }

    //zamknij pliki
    fclose(out);
    //

    print_file("TEMP/plik.maze");

    return 0;
}