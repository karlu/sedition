#include "glMain.h"

#include <stdio.h>
#include <string>

namespace SpaceWitch
{
	int createSdlWindow(SDL_Window** gWindow)
	{
		//SDL_Init(SDL_INIT_VIDEO)
		//Use OpenGL 2.1
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

		*gWindow = SDL_CreateWindow("Sedition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			return -1;
		}
		return 1;
	}

	int createSdlContext(SDL_GLContext* gContext, SDL_Window* gWindow)
	{
		*gContext = SDL_GL_CreateContext(gWindow);
		if (gContext == NULL)
		{
			printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
			return -1;
		}
		return 1;
	}

	int initGL()
	{
		if(SDL_GL_SetSwapInterval(1) < 0) //Use Vsync
		{
			printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
			return -1;
		}
		//TODO: Check what these does and have proper SDL Error checking
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glClearColor(0.f, 0.f, 0.f, 1.f);
		return 1;
	}

	void startDrawing()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
	}

	void publishDrawing(SDL_Window* gWindow)
	{
		SDL_GL_SwapWindow(gWindow);
	}

	void drawTriangle(Triangle &T)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(0.2f, 0.0f, 0.0f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		for (int j = 0; j<3; j++)
			glVertex3f(T.v[j].x, T.v[j].y, T.v[j].z);
		glEnd();
	}
}
