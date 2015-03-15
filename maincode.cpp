#include <SDL2/SDL.h>
#include <stdio.h>

#include "maincode.h"

using namespace SpaceWitch;

int main(int argc, char* args[])
{
	SWEnv* swEnv = new SWEnv();
	
	if(swEnv->isInitialized())
	{
		player[0] = Actor();
		sector[0] = Molecule();
		SDL_Event e;
		SDL_StartTextInput();

		while (!done)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					done = true;
				}
				calc();
				progKey(e);
			}

			//swEnv->render();
			swEnv->drawGLScene(player[0], sector[0], 1);
			

		}

		SDL_StopTextInput();
	}

	delete swEnv;

	return 0;
}


void calc()
{
	player[0].move(0.02);
}

void progKey(SDL_Event &e)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:				{ player[0].commands.FORWARD = true; break; }
	case SDLK_DOWN:				{ player[0].commands.BACKWARD = true; break; }
	case SDLK_RIGHT:			{ player[0].commands.RIGHT = true; break; }
	case SDL_SCANCODE_KP_6:		{ player[0].commands.RIGHT = true; break; }
	case SDLK_LEFT:				{ player[0].commands.LEFT = true; break; }
	case SDL_SCANCODE_KP_4:		{ player[0].commands.LEFT = true; break; }
	case SDL_SCANCODE_PAGEUP:	{ player[0].commands.PITCHUP = true; break; }
	case SDL_SCANCODE_KP_5:		{ player[0].commands.PITCHUP = true; break; }
	case SDL_SCANCODE_PAGEDOWN:	{ player[0].commands.PITCHDOWN = true; break; }
	case SDL_SCANCODE_KP_2:		{ player[0].commands.PITCHDOWN = true; break; }
	case SDL_SCANCODE_KP_1:		{ player[0].commands.ROLLUP = true; break; }
	case SDL_SCANCODE_KP_3:		{ player[0].commands.ROLLDOWN = true; break; }
	case SDLK_ESCAPE:			{ done = true; break; }
	}
}
