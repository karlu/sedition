#ifndef LOADMODEL_H
#define LOADMODEL_H

#include "atom.h"

#include <string>
#include <stdio.h>

namespace SpaceWitch
{
	void readstr(FILE *f, char *string);
	Atom SetupModel(char *adrs, Atom sector);
	void scrapComments(std::string &oneline);
}


#endif
