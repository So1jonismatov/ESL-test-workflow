.PHONY: all run clean debug

all: lib/libvector.a lib/3d_vector.h build/vector_test

lib/3d_vector.h: src/3d_vector.h
	@mkdir -p lib
	@cp src/3d_vector.h lib/3d_vector.h

lib/libvector.a: build/vector_ops.o
	@mkdir -p lib
	ar rcs lib/libvector.a build/vector_ops.o

build/vector_test: build/main.o lib/libvector.a
	@mkdir -p build
	gcc -I./lib -Wall -g $(shell pkg-config --cflags check) -L./lib build/main.o -o build/vector_test -lvector $(shell pkg-config --libs check) -lm

build/vector_ops.o: src/vector_ops.c
	@mkdir -p build
	gcc -I./src -Wall -g -c src/vector_ops.c -o build/vector_ops.o

build/main.o: tests/main.c lib/3d_vector.h
	@mkdir -p build
	gcc -I./lib -Wall -g $(shell pkg-config --cflags check) -c tests/main.c -o build/main.o

run: all
	./build/vector_test

clean:
	rm -rf build lib

debug: clean all
	gdb ./build/vector_test
