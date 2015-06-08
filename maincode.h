#ifndef MAINCODE_H
#define MAINCODE_H

#include "swmath.h"
#include "swcon.h"
#include "swmodel.h"
#include "swgl.h"

using namespace SpaceWitch;

void calc();
void progKey(SDL_Event &e);

bool	done=false;
double currentTime = 0;

Actor sector[1];
Actor player[1];
World *world;

#endif
