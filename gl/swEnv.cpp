#include "swEnv.h"

namespace SpaceWitch
{
	SWEnv::SWEnv()
	{
		if(initialize())
			initialized = true;
	}

	SWEnv::~SWEnv()
	{
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;

		SDL_Quit();
	}

	int SWEnv::initialize()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
			return -1;
		}

		if(createSdlWindow(&gWindow) < 0) return -1;
		if(createSdlContext(&gContext, gWindow) < 0) return -1;
		if(initGL() < 0) return -1;

		return 1;		
	}
	

	int SWEnv::drawGLScene(World* W)
	{
		startDrawing();

		glColor3f(1.0f, 1.0f, 1.0f);

		publishDrawing(gWindow);
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
}
