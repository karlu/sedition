#ifndef SWLOADMODEL_H
#define SWLOADMODEL_H

#include "swAtom.h"

#include <string>
#include <stdio.h>

namespace SpaceWitch
{
	void readstr(FILE *f, char *string);
	Atom SetupModel(char *adrs, Atom sector);
	void scrapComments(std::string &oneline);
}


#endif