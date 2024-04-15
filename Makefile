all: solver preprocessor bin_to_txt


solver:
	gcc -Wall src/*.c -o solver

preprocessor:
	gcc -Wall src_preprocessor/*.c -o graph

bin_to_txt:
	gcc -Wall src_bin_to_maze/*.c -o bin

clean:
	rm bin graph solver