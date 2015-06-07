#ifndef MODELPARSER_H
#define MODELPARSER_H

#include "world.h"

#include <string>
#include <vector>

namespace SpaceWitch
{
	struct ParseArg
	{
		std::vector<std::string> arg;
	};


	void parseToWorld(World& W); //std::string* filename, World& W);


}

#endif
