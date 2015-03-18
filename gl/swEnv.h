#ifndef SWENV_H
#define SWENV_H

#include "glMain.h"
#include "swmodel.h"

#include <SDL2/SDL.h>

namespace SpaceWitch
{
	class SWEnv
	{
	public:
		SWEnv();
		~SWEnv();
		int initialize();
		bool isInitialized() const { return initialized; }
		int drawGLScene(World*);

	private:
		void drawMolecule(Molecule &S);
		
		// Graphics
		SDL_Window* gWindow = NULL;
		SDL_GLContext gContext;

		// Misc
		bool initialized = false;
	};
}

#endif
