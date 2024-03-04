#include "errors.h"

int check_input_err(const int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "%s: Brak podanego pliku.\n", argv[0]);
        return 1;
    }
    return 0;
}

int check_err(FILE *in, FILE *out, const int height, const int width, char **argv) {
    if (in == NULL) {
        fprintf(stderr, "%s: Nie można otworzyć pliku %s\n", argv[0], argv[1]);
        return 2;
    }

    if (out == NULL) {
        fprintf(stderr, "%s: Nie można stworzyć pliku copy.maze\n", argv[0]);
        fclose(in);
        return 3;
    }

    if (height > 2048 || width > 2048) {
        fprintf(stderr, "%s: Za duży labirynt. Maksymalne rozmiary: 1024x1024 liczone po ścieżkach.\n", argv[0]);
        fclose(in);
        fclose(out);
        return 4;
    } else if (height <4 || width <3 ) {
        fprintf(stderr, "%s: Za mały labirynt.\n", argv[0]);
        fclose(in);
        fclose(out);
        return 4;
    }
    return 0;
}