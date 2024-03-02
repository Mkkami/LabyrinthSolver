#include "ALL_H_FILES.h"

int main(int argc, char **argv) {
    FILE *in;
    int height, width;

    square *sqr = malloc(sizeof(square));
    MoveInstruction *minst = malloc(sizeof(MoveInstruction));

    in = fopen("TEMP/copy.maze", "r+");
    if (in == NULL) {
        fprintf(stderr, "%s: Plik copy.maze nie istnieje. Uruchom ./mcopy <plik_wejściowy> aby utworzyć ten plik.\n", argv[0]);
        fclose(in);
        return 2;
    }
    get_size(in, &height, &width);

    //
    fseek(in, 0, SEEK_SET);

    sqr_init(sqr);
    initiate(sqr, minst, in, height, width);


    fill_dead_end(sqr, minst, in, height, width);
    printf("Plik copy.maze został zmodyfikowany.\n\n")

    //zamknij pliki
    fclose(in);
    
    //free mem
    sqr_free(sqr, height);
    free(sqr);
    free(minst);


    return 0;
}
