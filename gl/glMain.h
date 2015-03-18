#ifndef GLMAIN_H
#define GLMAIN_H

#include "triangle.h"

#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <string>

namespace SpaceWitch
{
	int createSdlWindow(SDL_Window** gWindow);
	int createSdlContext(SDL_GLContext* gContext);
	int initGL();
	void drawTriangle(Triangle &T);
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
}

#endif
