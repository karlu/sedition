CC=g++
SDL_LIB=-L/usr/local/lib
GL_INCLUDE=-I/usr/include/SDL2 -I/usr/include/GL
CFLAGS=-std=c++11 -I. -I./math -I./include
CFLAGS_GL=$(CFLAGS) $(SDL_INCLUDE)

LDFLAGS=$(SDL_LIB)

SED_GL_LIBS=gl/triangle.o gl/atom.o gl/molecule.o gl/actor.o gl/camera.o gl/glMain.o gl/loadModel.o
SED_MATH_LIBS=math/vector.o math/matrix.o

.PHONY: all all_gl all_math build_dirs clean
all: build_dirs all_math all_gl sedition

sedition: maincode.cpp $(SED_GL_LIBS) $(SED_MATH_LIBS)
	cp maincode.cpp build/maincode.cpp
	cp maincode.h build/maincode.h
	cd build && $(CC) -o bin/$@ $^ $(CFLAGS_GL) $(LDFLAGS)

all_gl: $(SED_GL_LIBS)

gl/%.o: gl/%.cpp gl/%.h
	$(CC) -c $< $(CFLAGS_GL) -o build/$@

all_math: $(SED_MATH_LIBS)

math/%.o: math/%.cpp math/%.h
	$(CC) -c $< $(CFLAGS) -o build/$@

build_dirs:
	mkdir -p build/math >> /dev/null 2>&1 || true
	mkdir -p build/gl >> /dev/null 2>&1 || true
	mkdir -p build/bin >> /dev/null 2>&1 || true
	mkdir -p build/include >> /dev/null 2>&1 || true
	cp math/*.h build/include/
	cp gl/*.h build/include/

clean:
	rm -rf build/
	rm -f gl/*.o
	rm -f math/*.o
