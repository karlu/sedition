#ifndef GLMAIN_H
#define GLMAIN_H

#include "triangle.h"
#include "swmath.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

namespace SpaceWitch
{
	int createSdlWindow(SDL_Window** gWindow);
	int createSdlContext(SDL_GLContext* gContext, SDL_Window* gWindow);
	int initGL();
	void drawTriangle(Triangle &T);
	void startDrawing();
	void publishDrawing(SDL_Window* gWindow);
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
}

#endif
