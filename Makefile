CC=g++
#SDL_LIB=-L/usr/local/lib
SDL_LIB = -L/usr/local/lib -lSDL2 -lGL -lGLU -Wl,-rpath=/usr/local/lib
GL_INCLUDE=-I/usr/include/SDL2 -I/usr/include/GL
CFLAGS=-std=c++11 -I. -I./math -I./model -I./include
CFLAGS_GL=$(CFLAGS) $(SDL_INCLUDE)

LDFLAGS=$(SDL_LIB)

SED_MODEL_LIBS=model/triangle.o model/atom.o model/molecule.o model/actor.o model/world.o
SED_GL_LIBS=gl/camera.o gl/glMain.o gl/swEnv.o gl/loadModel.o
SED_MATH_LIBS=math/vector.o math/matrix.o

.PHONY: math_test model_test
.PHONY: all_math all_model all_gl all build_dirs clean

all: build_dirs all_math all_model all_gl sedition

model_test: modelTest.cpp build_dirs all_model all_math
	cp $< build/$<
	cd build && $(CC) $< $(SED_MATH_LIBS) $(SED_MODEL_LIBS) $(CFLAGS) -o bin/$@
	./build/bin/$@

math_test: mathTest.cpp build_dirs all_math
	cp $< build/$<
	cd build && $(CC) $< $(SED_MATH_LIBS) $(CFLAGS) -o bin/$@
	./build/bin/$@

sedition: maincode.cpp $(SED_GL_LIBS) $(SED_MATH_LIBS) $(SED_MODEL_LIBS)
	cp maincode.cpp build/maincode.cpp
	cp maincode.h build/maincode.h
	cd build && $(CC) -o bin/$@ $^ $(CFLAGS_GL) $(LDFLAGS)

all_gl: $(SED_GL_LIBS)

gl/%.o: gl/%.cpp gl/%.h
	$(CC) -c $< $(CFLAGS_GL) -o build/$@

all_model: $(SED_MODEL_LIBS)

model/%.o: model/%.cpp model/%.h
	$(CC) -c $< $(CFLAGS) -o build/$@

all_math: $(SED_MATH_LIBS)

math/%.o: math/%.cpp math/%.h
	$(CC) -c $< $(CFLAGS) -o build/$@

build_dirs:
	mkdir -p build/math >> /dev/null 2>&1 || true
	mkdir -p build/gl >> /dev/null 2>&1 || true
	mkdir -p build/model >> /dev/null 2>&1 || true
	mkdir -p build/bin >> /dev/null 2>&1 || true
	mkdir -p build/include >> /dev/null 2>&1 || true
	cp math/*.h build/include/
	cp model/*.h build/include/
	cp gl/*.h build/include/

clean:
	rm -rf build/
