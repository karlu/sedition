#ifndef GLMAIN_H
#define GLMAIN_H

#include "actor.h"

#include <SDL2/SDL.h>

namespace SpaceWitch
{
	class SWEnv
	{
	public:
		SWEnv();
		~SWEnv();
		bool isInitialized() const { return initialized; }
		int drawTriangle(Triangle*);

	private:
		bool initGL();
		
		// Graphics
		bool gRenderQuad = true;
		SDL_Window* gWindow = NULL;
		SDL_GLContext gContext;

		// Misc
		bool initialized = false;
	};
}

#endif
