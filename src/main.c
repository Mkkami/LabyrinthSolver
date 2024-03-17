#include "ALL_H_FILES.h"
#include <unistd.h>

int main(int argc, char **argv) {

    int maze_height = 0, maze_width = 0;
    int placed_walls = 0;

    chunk *ck = malloc(sizeof(chunk));
    enum Direction dir = NORTH;

    opterr = 0;

    char c;
    char *input_filename = NULL;
    char *output_filename = NULL;
    char *copy_filename = NULL;
    while ((c = getopt(argc, argv, "f:o:c:")) != -1) {
        switch (c) {
            case 'f':
                input_filename = optarg;
                break;
            case 'o':
                output_filename = optarg;
                break;
            case 'c':
                copy_filename = optarg;
                break;
            default:
                break;
        }
    }

    if (input_filename == NULL) {
        fprintf(stderr, "%s: Brak podanego pliku wejściowego. Program kończy działanie.\n", argv[0]);
        return -1;
    }
    
    if (copy_filename == NULL) {
        fprintf(stderr, "%s: Brak podanej ścieżki do zapisania zmienionego pliku. Zostanie zapisany jako "
                            "'copy.maze'. Czy chcesz kontynuować? (T/N)  ", argv[0]);
        char response;
        scanf( " %c", &response);
        if (response != 'T' && response != 't') {
            fprintf(stderr, "Zakończono działanie programu.\n");
            return -2; 
        }
        copy_filename = "copy.maze";
    }
    
    FILE *in;
    in = fopen(input_filename, "r"); //read only
    if (in == NULL) {
        fprintf(stderr, "%s: Plik %s nie istnieje.\n", argv[0], input_filename);
        fclose(in);
        return 1;
    }
    FILE *out;
    if (output_filename == NULL) {
        out = stderr;
    } else {
        out = fopen(output_filename, "w+"); //create, read + write
        if (out == NULL) {
            fprintf(stderr, "%s: Błąd tworzenia pliku wyjściowego %s. "
                                "Upewnij się że program ma odpowiednie uprawnienia.\n",
                                argv[0], copy_filename);
            return 2;
        }
    }

    FILE *copy;
    copy = fopen(copy_filename, "w+"); //create, read + write
    if (copy == NULL) {
        fprintf(stderr, "%s: Błąd tworzenia pliku wyjściowego %s. "
                        "Upewnij się że program ma odpowiednie uprawnienia.\n",
                         argv[0], copy_filename);
        return 2;
    }

    get_maze_size(in, &maze_height, &maze_width);
    //printf("%d, %d\n", maze_height, maze_width);

    //copy and close input
    copy_file(in, copy);
    fclose(in);

    
    initiate(ck, &dir, copy, maze_height, maze_width);
    //print_dir(dir);


    placed_walls = fill_dead_end(ck, &dir, copy, maze_height, maze_width);
    printf("Plik %s został zmodyfikowany.\n", copy_filename);
    printf("Ilość wypełnionych pól: %d\n\n", placed_walls);

    
    fclose(copy);
    if (out != stderr) {
        fclose(out);
    }
    
    //free mem
    // ck_free(ck, height);
    free(ck);
    // free(minst);


    return 0;
}
