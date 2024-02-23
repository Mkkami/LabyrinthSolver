all:
	gcc -Wall src/*.c -o bin/lsolve

clean:
	rm -f bin/*

mem_check:
	valgrind --leak-check=full ./bin/lsolve maze_files/$(FILE)

run:
	./bin/lsolve maze_files/$(FILE)