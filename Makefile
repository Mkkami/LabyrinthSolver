all:
	gcc -Wall src_copy/*.c -o mcopy
	gcc -Wall src/*.c -o msolve

copy:
	./bin/mcopy maze_files/$(F)

clean:
	rm -f TEMP/*