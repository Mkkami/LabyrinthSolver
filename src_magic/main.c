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
    initiate(sqr, minst, out, height, width);
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
    initiate(sqr, minst, out, height, width);
    fseek(out, 0, SEEK_SET);

    mark_shortest_path(sqr, minst, out, height, width);

    //zamknij pliki
    fclose(out);
    //

    print_file("TEMP/plik.maze");

    return 0;
}