#include "modelparser.h"

#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include <sstream>
#include <algorithm>
#include <iterator>


using namespace std;

namespace SpaceWitch
{

	//static void ModelParser::parseToWorld(string* filename, World& W)
	void parseToWorld(World& W)
	{
		
		fstream file("data/sector.mol", ifstream::in);
		string str;

		Molecule* m = new Molecule();
		Atom* a = new Atom();

		std::vector<ParseArg> args;

		while(getline(file, str))
		{
			if(str.size() == 0)
				continue;

			istringstream iss(str);
			std::vector<string> tokens;
			copy(istream_iterator<string>(iss),
				 istream_iterator<string>(),
				 back_inserter(tokens));

			ParseArg pa;
			pa.arg = tokens;
			args.push_back(pa);
		}

		cout << args.size();

	}
}
