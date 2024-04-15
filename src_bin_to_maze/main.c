#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s{
    int File_Id;
    char ESC;
    short columns;
    short lines;
    short entryx;
    short entryy;
    short exitx;
    short exity;
    char reserved[12];
    int counter;
    int solution_offset;
    char separator;
    char wall;
    char path;
} __attribute__((packed)) head;

struct sk {
    unsigned char separator;
    unsigned char value;
    unsigned char count;
} __attribute__((packed)) typedef keywords;


int main(int argc, char** argv)
{

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
                fprintf(stdout, "help: ./bin -f <plik_wejsciowy> -o <plik_wyjsciowy>\n");
                return 0;
            default:
                fprintf(stdout, "help: ./bin -f <plik_wejsciowy> -o <plik_wyjsciowy>\n");
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
    in = fopen(input_filename, "rb"); //read binary
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

    head header;

    fread(&header, 40, 1, in);

    printf("File_Id: 0x%x\n", header.File_Id);
    printf("ESC: 0x%x\n", header.ESC);
    printf("Columns: %d\n", header.columns);
    printf("Lines: %d\n", header.lines);
    printf("Entry X: %d\n", header.entryx);
    printf("Entry Y: %d\n", header.entryy);
    printf("Exit X: %d\n", header.exitx);
    printf("Exit Y: %d\n", header.exity);
    printf("Counter: %d\n", header.counter);
    printf("Solution Offset: %d\n", header.solution_offset);
    printf("Separator: \'%c\'\n", header.separator);
    printf("Wall: \'%c\'\n", header.wall);
    printf("Path: \'%c\'\n", header.path);


    header.entryx--; header.entryy--;
    header.exitx--; header.exity--;

    char **board;
    board = malloc(sizeof(char*)*header.lines);
    for (int i = 0; i < header.lines; i++) {
        board[i] = malloc(sizeof(char)*header.columns);
    }
    
    keywords kw;
    int total_count = 0;
    for (int i = 0; i < header.counter; i++) {

        fread(&kw, 3, 1, in);

        for (int j = 0; j < kw.count+1; j++) {

            int x = total_count % header.columns;
            int y = total_count / header.columns;
            total_count++;

            if (kw.value == header.path)
                board[x][y] = ' ';
            else if (kw.value == header.wall)
                board[x][y] = 'X';
            
        }
    }
    board[header.entryx][header.entryy] = 'P';
    board[header.exitx][header.exity] = 'K';

    for (int i = 0; i < header.lines; i++) {
        for (int j = 0; j < header.columns; j++) {
            fprintf(out, "%c", board[i][j]);
        }
        fprintf(out, "\n");
    }



    fclose(out);
    fclose(in);

    
    return 0;

}
