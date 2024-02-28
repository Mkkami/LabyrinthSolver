all:
	gcc -Wall src/*.c -o bin/lsolve

clean:
	rm -f bin/*

mem_check:
	valgrind --leak-check=full ./bin/lsolve maze_files/$(FILE)

run:
	./bin/lsolve maze_files/$(FILE)

magic:
	gcc -Wall src_magic/*.c -o bin/modfile

modify:
	./bin/modfile

comcopy:
	gcc -Wall src_copy/*.c -o bin/mcopy

copy:
	./bin/mcopy maze_files/$(F)