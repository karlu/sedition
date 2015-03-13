CC=g++
CFLAGS="-std=c++11 -Wall -I./math/"

MATH_DEPS="math/swVector.h math/swCommonMath.h"

build/swMatrix.o: math/swMatrix.c math/swMatrix.h build/swVector.o $(MATH_DEPS)
  $(CC) $(CFLAGS) -c $@

build/swVector.o: math/swVector.c $(MATH_DEPS)
  $(CC) $(CFLAGS) -c $@
