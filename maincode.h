#ifndef MAINCODE_H
#define MAINCODE_H

#include "swMolecule.h"
#include "swActor.h"
#include "swGlMain.h"

using namespace SpaceWitch;

void calc();
void progKey(SDL_Event &e);

bool	done=false;

Molecule sector[1];
Actor player[1];

//LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

#endif