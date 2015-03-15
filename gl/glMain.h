#ifndef GLMAIN_H
#define GLMAIN_H

#include "molecule.h"
#include "actor.h"

#include <SDL.h>

namespace SpaceWitch
{
	class SWEnv
	{
	public:
		SWEnv();
		~SWEnv();
		void update();
		void render();
		bool isInitialized() const { return initialized; }
		int drawGLScene(Actor &P, Molecule &S, int nMolecules);

	private:
		bool initGL();
		void drawMolecule(Molecule &S);
		

		// Graphics
		bool gRenderQuad = true;
		SDL_Window* gWindow = NULL;
		SDL_GLContext gContext;

		// Misc
		bool initialized = false;
		
		// Experiment
		//void drawGLScene();
	};
	
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
}

#endif
