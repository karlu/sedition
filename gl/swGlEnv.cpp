#include "swGlEnv.h"

namespace SpaceWitch
{
	SWGLEnv::SWGLEnv()
	{
		gContext = SDL_GL_CreateContext(gWindow);
		if (gContext == NULL)
		{
			printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
		}
		else if(SDL_GL_SetSwapInterval(1) < 0)
		{
			printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
		}
		else if (!initGL())
		{
			printf("Unable to initialize OpenGL!\n");
		}
		else
		{
			initialized = true;
		}
	}
	
	SWGLEnv::~SWGLEnv()
	{
		gWindow = NULL;
	}

	bool SWGLEnv::initGL()
	{
		bool success = true;
		GLenum error = GL_NO_ERROR;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

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

		glClearColor(0.f, 0.f, 0.f, 1.f);

		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printf("Error initializing OpenGL! %s\n", gluErrorString(error));
			success = false;
		}

		return success;
	}

	void SWGLEnv::swapWindow()
	{
		SDL_GL_SwapWindow(gWindow);
	}
	
	// Insert color arg
	void drawTriangle(Triangle &T)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(0.2f, 0.0f, 0.0f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		for (int j = 0; j<3; j++)
			glVertex3f(T.v[j].x, T.v[j].y, T.v[j].z);
		glEnd();
	}

	void SWGLEnv::clearWindow()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glRasterPos2f(0, 0);
	}
}
