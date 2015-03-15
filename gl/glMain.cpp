#include "glMain.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <stdio.h>
#include <string>

namespace SpaceWitch
{
	SWEnv::SWEnv()
	{
		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Use OpenGL 2.1
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

			//Create window
			gWindow = SDL_CreateWindow("Sedition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
			if (gWindow == NULL)
			{
				printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Create context
				gContext = SDL_GL_CreateContext(gWindow);
				if (gContext == NULL)
				{
					printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				}
				else if(SDL_GL_SetSwapInterval(1) < 0) //Use Vsync
				{
					printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
				}
				else if (!initGL()) //Initialize OpenGL
				{
					printf("Unable to initialize OpenGL!\n");
				}
				else
				{
					initialized = true;
				}
				
			}
		}
	}
	
	SWEnv::~SWEnv()
	{

		//Destroy window	
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;

		//Quit SDL subsystems
		SDL_Quit();
	}

	bool SWEnv::initGL()
	{
		bool success = true;
		GLenum error = GL_NO_ERROR;

		//Initialize Projection Matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		//Check for error
		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printf("Error initializing OpenGL! %s\n", gluErrorString(error));
			success = false;
		}

		//Initialize Modelview Matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Check for error
		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printf("Error initializing OpenGL! %s\n", gluErrorString(error));
			success = false;
		}

		//Initialize clear color
		glClearColor(0.f, 0.f, 0.f, 1.f);

		//Check for error
		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printf("Error initializing OpenGL! %s\n", gluErrorString(error));
			success = false;
		}

		return success;
	}

	void SWEnv::render()
	{
		//Clear color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		//Render quad
		if (gRenderQuad)
		{
			glBegin(GL_QUADS);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(-0.5f, 0.5f);
			glEnd();
		}
		SDL_GL_SwapWindow(gWindow);
	}

	void SWEnv::update()
	{
		//No per frame update needed
	}
	
	void SWEnv::drawMolecule(Molecule &S)
	{
		for (int i = 0; i < S.nTriangles(); i++)
		{
			glBegin(GL_TRIANGLES);
			glColor3f(i*0.2f, 0.0f, 0.0f);
			glNormal3f(0.0f, 0.0f, 1.0f);
			Triangle* t = S.getTriangle(i);
			for (int j = 0; j<3; j++)
				glVertex3f(t->v[j].x, t->v[j].y, t->v[j].z);
			glEnd();
		}
	}





	int SWEnv::drawGLScene(Actor &P, Molecule &S, int nMolecules)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glColor3f(1.0f, 1.0f, 1.0f);

		// Insert to Cam class
		// ----------------------

		Vector pDir, pTop;
		Vector pPos = P.getPosition();
		P.getDirection(pDir);
		P.getTop(pTop);
		double camAngle = 0.5;
		double lookAt = 2;
		Vector camPos = pPos - pDir * cos(camAngle) - pTop * sin(camAngle);
		Vector camFocus = pPos + pDir*lookAt;
		

		// ----------------------

		gluLookAt(
			camPos.x, camPos.y, camPos.z,
			camFocus.x, camFocus.y, camFocus.z,
			pTop.x, pTop.y, pTop.z);

		drawMolecule(S);

		for (int i = 0; i < P.model.nTriangles(); i++)
		{
			glBegin(GL_TRIANGLES);
			glColor3f(i*0.2f, 1.0f, 0.0f);
			glNormal3f(0.0f, 0.0f, 1.0f);
			for (int j = 0; j<3; j++)
			{
				Vector* v = &(P.model.getTriangle(i)->v[j]);
				Vector rv;
				P.rotVector(rv, *v);
				glVertex3f(rv.x, rv.y, rv.z);
			}
			glEnd();
		}

		glRasterPos2f(0, 0);

		return TRUE;
	}
}
