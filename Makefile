CC=g++
CFLAGS=

MATH_DEPS=math/swVector.h math/swCommonMath.h

.PHONY: all
all: build/swVector.o build/swMatrix.o

build/swMatrix.o: math/swMatrix.cpp math/swMatrix.h math/swVector.h math/swCommonMath.h
	g++ -c math/swMatrix.cpp

build/swVector.o: math/swVector.cpp math/swVector.h math/swCommonMath.h
	g++ -c math/swVector.cpp
