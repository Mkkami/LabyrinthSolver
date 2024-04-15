#include "file_reader.h"
#include "maze_to_graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {


    char c;
    char *input_filename = NULL;
    char *output_filename = NULL;
    
    while ((c = getopt(argc, argv, "f:o:h")) != -1) {
        switch (c) {
            case 'f':
                input_filename = optarg;
                break;
            case 'o':
                output_filename = optarg;
                break;
            case 'h':
                fprintf(stdout, "help: ./graph -f <plik_wejsciowy> -o <plik_wyjsciowy>\n");
                return 0;
            default:
                fprintf(stdout, "help: ./graph -f <plik_wejsciowy> -o <plik_wyjsciowy>\n");
                return 0;
        }
    }
    if (input_filename == NULL) {
        fprintf(stderr, "%s: Brak podanego pliku wejściowego. Program kończy działanie.\n", argv[0]);
        return -1;
    }
    
    if (output_filename == NULL) {
        fprintf(stderr, "%s: Brak podanej ścieżki do zapisania pliku. Program kończy działanie.\n ", argv[0]);
        return -1;
    }

    FILE *in;
    in = fopen(input_filename, "r"); //read only
    if (in == NULL) {
        fprintf(stderr, "%s: Plik %s nie istnieje.\n", argv[0], input_filename);
        fclose(in);
        return 1;
    }
    FILE *out;
    out = fopen(output_filename, "w+"); //create, read + write
    if (out == NULL) {
        fprintf(stderr, "%s: Błąd tworzenia pliku wyjściowego %s. "
                        "Upewnij się że program ma odpowiednie uprawnienia.\n",
                         argv[0], output_filename);
        return 2;
    }

    int start[2];
    int end[2];

    int height, width;

    get_maze_size(in, &height, &width, start, end);

    char **board;
    int **ID;
    board = malloc(sizeof(char*)*height);
    ID = malloc(sizeof(int*)*height);
    for (int i = 0; i < height; i++) {
        board[i] = malloc(sizeof(char)*width);
        ID[i] = malloc(sizeof(int)*width);
    }

    read_file_to_mem(in, board, height, width);
    fclose(in);

    int placed;
    placed = placer(board, height, width);
    ID_fill(board, ID, height, width);
    //print_board(board, height, width);

    fprintf(out, "%d %d %d\n", placed, ID[start[0]][start[1]], ID[end[0]][end[1]]);

    connecter(board, ID, height,  width,  placed, out);

    printf("placed nodes: %d\n", placed);
    printf("h: %d, w: %d\n", height, width);

    
    for (int i = 0; i < height; i++) {
        free(board[i]);
        free(ID[i]);
    }
    free(board);
    free(ID);
    fclose(out);



    return 0;
}