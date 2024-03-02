#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char **argv) {
    FILE *in, *out;
    int height, width;
    char elem;

    if (argc < 2) {
        fprintf(stderr, "%s: Brak podanego pliku.\n", argv[0]);
        return 1;
    }

    in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "%s: Nie można otworzyć pliku %s\n", argv[0], argv[1]);
        return 2;
    }

    out = fopen("TEMP/copy.maze", "w+");
    if (out == NULL) {
        fprintf(stderr, "%s: Nie można stworzyć pliku copy.maze\n", argv[0]);
        fclose(in);
        return 3;
    }
    get_size(in, &height, &width);
    if (height > 2048 || width > 2048) {
        fprintf(stderr, "%s: Za duży labirynt. Maksymalne rozmiary: 1024x1024 liczone po ścieżkach.\n", argv[0]);
        fclose(in);
        fclose(out);
        return -1;
    } else if (height <4 || width <3 ) {
        fprintf(stderr, "%s: Za mały labirynt.\n", argv[0]);
        fclose(in);
        fclose(out);
        return -1;
    }

    //wypełnij plik

    // Dodanie górnej ściany labiryntu
    for (int i = 0; i < width + 2; i++) {
        fputc('X', out);
    }
    fputc('\n', out);
    fputc('X', out);
    // Dodanie ścian po lewej i po prawej stronie oraz skopiowanie zawartości labiryntu
    while ((elem = fgetc(in)) != EOF) {
        if (elem == '\n') {
            fputc('X', out); // Dodanie ściany po lewej stronie
            fputc('\n', out); // Przejście do nowej linii
            fputc('X', out); // Dodanie ściany na początku nowej linii
        } else {
            fputc(elem, out); // Skopiowanie aktualnego elementu z labiryntu
        }
        //fputc('X', out); // Dodanie ściany po prawej stronie
    }

    // Dodanie dolnej ściany labiryntu
    for (int i = 0; i < width + 1; i++) {
        fputc('X', out);
    }
    fputc('\n', out);

    fclose(in);
    fclose(out);

    printf("Kopia pliku %s została utworzona w TEMP/copy.maze\n", argv[1]);

    return 0;
}