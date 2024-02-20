all:
	gcc -Wall src/*.c -o bin/lsolve

clean:
	rm -f bin/*
