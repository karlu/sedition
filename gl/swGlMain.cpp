//#include "swCommonMath.h"
//#include "swVector.h"
#include "swGlMain.h"

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

		/*
		if (!LoadGLTextures())
			return 0;

		sector[0] = SetupModel("Data/sector.txt", sector[0]);
		sector[0].list = BuildList(sector[0], sector[0].list);
		p[i].model = SetupModel("Data/Shipklö.txt", p[i].model);
		*/

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



	/*
	GLuint BuildList(TMolecule sector, GLuint list)
	{
	list = glGenLists(1);
	int i, j;
	GLfloat x_m, y_m, z_m, u_m, v_m;
	glNewList(list, GL_COMPILE);
	for (i = 0; i < sector.numtriangles; i++)
	{
	glBindTexture(GL_TEXTURE_2D, tx[sector.triangle[i].t * 3].image[filter]);
	//glBindTexture(GL_TEXTURE_2D, texture[filter+sector.triangle[i].t*3]);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0f, 0.0f, 1.0f);
	for (j = 0; j<3; j++)
	{

	x_m = sector.triangle[i].vertex[j].x;
	y_m = sector.triangle[i].vertex[j].y;
	z_m = sector.triangle[i].vertex[j].z;
	//	x_m = (float)x1*cos(yrot)-z1*sin(yrot)+shipx;
	//	y_m = y1+shipy;
	//	z_m = (float)-x1*sin(yrot)-z1*cos(yrot)+shipz;
	u_m = sector.triangle[i].vertex[j].u;
	v_m = sector.triangle[i].vertex[j].v;
	glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);
	}
	glEnd();
	}
	glEndList();

	return list;
	}
	*/

	/*
	void drawGLScene(GLvoid)
	{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The View

	glLightfv(GL_LIGHT1, GL_POSITION, lPos);	// Position The Light

	glLoadIdentity();									// Reset The View
	glColor3f(1.0f, 1.0f, 1.0f);

	gluLookAt(
	p[0].x + (p[0].bias + .5)*p[0].top.X() + 1.2*p[0].dir.X() - p[0].dir.X()*p[0].camDist * 2,
	p[0].y + (p[0].bias + .5)*p[0].top.Y() + 1.2*p[0].dir.Y() - p[0].dir.Y()*p[0].camDist * 2,
	p[0].z + (p[0].bias + .5)*p[0].top.Z() + 1.2*p[0].dir.Z() - p[0].dir.Z()*p[0].camDist * 2,

	p[0].x + 10 * p[0].dir.X(),
	p[0].y + 10 * p[0].dir.Y(),
	p[0].z + 10 * p[0].dir.Z(),

	p[0].top.X(),
	p[0].top.Y(),
	p[0].top.Z());

	glCallList(sector[0].list);

	Matrix temp1, temp2 = Matrix();
	temp1 = p[0].bas;
	temp2.Rot(0, 0, p[0].vib);

	temp1 *= temp2;



	int i, j;

	//glRotatef(p[0].vib,p[0].dir.X(),p[0].dir.Y(),p[0].dir.Z());
	for (i = 0; i < p[0].model.numtriangles; i++)
	{
	//glBindTexture(GL_TEXTURE_2D, tx[p[0].model.triangle[i].t].image[filter]);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0f, 0.0f, 1.0f);
	for (j = 0; j<3; j++)
	{

	float x1 = p[0].model.triangle[i].vertex[j].x;
	float y1 = -p[0].model.triangle[i].vertex[j].y;
	float z1 = -p[0].model.triangle[i].vertex[j].z;
	float x_m = p[0].x + (x1*p[0].side.X() + y1*p[0].top.X() + z1*p[0].dir.X());
	float y_m = p[0].y + (x1*p[0].side.Y() + y1*p[0].top.Y() + z1*p[0].dir.Y());
	float z_m = p[0].z + (x1*p[0].side.Z() + y1*p[0].top.Z() + z1*p[0].dir.Z());
	//float x_m = p[0].x + ( x1*temp1(0,0) + y1*temp1(1,0) + z1*temp1(2,0) );
	//float y_m = p[0].y + ( x1*temp1(0,1) + y1*temp1(1,1) + z1*temp1(2,1) );
	//float z_m = p[0].z + ( x1*temp1(0,2) + y1*temp1(1,2) + z1*temp1(2,2) );
	float u_m = p[0].model.triangle[i].vertex[j].u;
	float v_m = p[0].model.triangle[i].vertex[j].v;
	glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);
	}
	glEnd();
	}



	if (p[0].vib>0)
	p[0].vib -= 0.001f;
	if (p[0].vib<0)
	p[0].vib += 0.001f;
	glColor3f(1.0f, 0.0f, 0.0f);

	glRasterPos2f(0, 0);
	}
	*/


	
}