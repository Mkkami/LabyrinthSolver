#include "graph_reader.h"
#include "graph.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

    char c;
    char *input_filename = NULL;
    char *output_filename = NULL;
    
    while ((c = getopt(argc, argv, "f:o:c:h")) != -1) {
        switch (c) {
            case 'f':
                input_filename = optarg;
                break;
            case 'o':
                output_filename = optarg;
                break;
            case 'h':
                fprintf(stdout, "help: ./solver -f <plik_wejsciowy> -o <plik_wyjsciowy>");
                fprintf(stdout, "\n Przykład użycia: ");
                fprintf(stdout, "\n./solver -f mgraph.txt -o output.txt\n");
                return 0;
            default:
                fprintf(stdout, "help: ./solver -f <plik_wejsciowy> -o <plik_wyjsciowy>");
                fprintf(stdout, "\n Przykład użycia: ");
                fprintf(stdout, "\n./solver -f mgraph.txt -o output.txt\n");
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

    int node_count = get_node_count(in);
    printf("Nodes: %d\n", node_count);

    int start_ID;
    int end_ID;
    get_start_end_ID(&start_ID, &end_ID, in);
    printf("s: %d, e: %d\n", start_ID, end_ID);
 

    Graph *graph = createGraph(node_count);
    Position *position = createPositionList(node_count);

    fillGraph(graph, position, in);

    dijkstra(graph, start_ID, end_ID, out, position);

    fclose(in);
    fclose(out);
    freeGraph(graph);
    free(position);
    printf("siema dziala");

    return 0;
}