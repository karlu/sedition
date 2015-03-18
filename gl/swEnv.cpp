#include "glMain.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <string>

namespace SpaceWitch
{
	SWEnv::SWEnv()
	{
		initialize();
	}

	int SWEnv::initialize()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
			return -1;
		}

		if(createSdlWindow(&gWindow) < 0) return -1;
		if(createSdlContext(&gContext) < 0) return -1;
		if(initGL() < 0) return -1;

		return 1;		
	}
	
	SWEnv::~SWEnv()
	{
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;

		SDL_Quit();
	}

	void SWEnv::drawMolecule(Molecule &S)
	{
		for (int i = 0; i < S.nAtoms(); i++)
		{
			Atom* tmp = S.getAtom(i);
			for (int j = 0; j < tmp->nTriangles(); j++)
			{
				Triangle *tri = tmp->getTriangle(j);
				drawTriangle(*tri);
			}
		}
	}

	int SWEnv::drawGLScene(World* W)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glColor3f(1.0f, 1.0f, 1.0f);

		SDL_GL_SwapWindow(gWindow);
		return true;
	}
}
