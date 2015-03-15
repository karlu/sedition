CC=g++
CFLAGS=-std=c++11 -I. -I./math

.PHONY: all all_gl all_math build_dirs clean
all: build_dirs all_math all_gl

all_gl: gl/triangle.o gl/atom.o gl/actor.o gl/camera.o

gl/%.o: gl/%.cpp
	$(CC) -c $< $(CFLAGS) -o build/$@

all_math: math/vector.o math/matrix.o

math/%.o: math/%.cpp
	$(CC) -c $< $(CFLAGS) -o build/$@

build_dirs:
	mkdir -p build/math >> /dev/null 2>&1 || true
	mkdir -p build/gl >> /dev/null 2>&1 || true

clean:
	rm -rf build/
