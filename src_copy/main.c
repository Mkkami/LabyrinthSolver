#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "errors.h"

int main(int argc, char **argv) {
    FILE *in, *out;
    int height, width;
    char elem;

    int Err_val;
    //Sprawdzenie czy jest plik
    Err_val = check_input_err(argc, argv);
    if (Err_val != 0)
        return Err_val;

    in = fopen(argv[1], "r");
    get_size(in, &height, &width);

    //Sprawdzenie innych błędów
    out = fopen("TEMP/copy.maze", "w+");
    Err_val = check_err(in, out, height, width, argv);
    if (Err_val != 0)
        return Err_val;



    //wypełnij plik

    // górna ściana
    for (int i = 0; i < width + 2; i++) {
        fputc('X', out);
    }
    fputc('\n', out);
    fputc('X', out);
    // ściany po lewej o po prawej
    while ((elem = fgetc(in)) != EOF) {
        if (elem == '\n') {
            fputc('X', out); // koniec linii
            fputc('\n', out); 
            fputc('X', out); // początek linii
        } else if (elem != '\r') {  // pliki stworzone na windowsie mają \r\n zamiast \n
            fputc(elem, out);
        }
    }

    // dolna ściana
    for (int i = 0; i < width + 1; i++) {
        fputc('X', out);
    }
    fputc('\n', out);

    fclose(in);
    fclose(out);

    printf("Kopia pliku %s została utworzona w TEMP/copy.maze\n", argv[1]);

    return 0;
}