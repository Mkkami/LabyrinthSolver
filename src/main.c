#include <stdio.h>
#include <stdlib.h>
#include "laby.h"
#include "file.h"

int main(int argc, char **argv) {
    FILE *in = NULL;
    int height = 0;
    int width = 0;

    labyrinth *lab = malloc(sizeof(labyrinth));
    if (lab == NULL) {
        fprintf(stderr, "%s: Nie mozna alokowac pamieci dla lab\n", argv[0]);
        return 1;
    }

    if (argc > 1) {
        in = fopen(argv[1], "r");
    } else {
        fprintf(stderr, "%s: Brak podanego pliku wejsciowego\n", argv[0]);
        free(lab);
        return 1;
    }

    if (in == NULL) { 
        fprintf(stderr, "%s: Nie mozna czytac pliku %s\n", argv[0], argv[1]);
        free(lab);
        return 2;
    }
    get_size(in, &height, &width);

    lab_init(lab, height, width);
    lab_fill(lab, in, width);
    lab_print(lab, height, width);

    printf("%d, %d\n", lab->pos_x, lab->pos_y);

    fclose(in);
    lab_free(lab, height);
    free(lab);

    return 0;
}