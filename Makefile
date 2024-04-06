all:
	gcc -Wall src/*.c -o solver

preprocessor:
	gcc -Wall src_preprocessor/*.c -o graph

