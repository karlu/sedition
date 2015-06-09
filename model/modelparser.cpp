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
		
		std::vector<ParseArg> args = parseFile("data/sector.mol");
		Molecule* mol = parseArgList(args);


		cout << args.size();

	}

	std::vector<ParseArg> parseFile(string& filename)
	{
		fstream file("data/sector.mol", ifstream::in);
		string str;

		std::vector<ParseArg> args;

		while(getline(file, str))
		{
			scrapComments(str);
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

		return args;
	}

	void scrapComments(string& oneline)
	{
		int pos = oneline.find('#');
		oneline.erase(pos, oneline.size());
	}

	void parseArgList(vector<ParseArg>& args)
	{
		std::vector<Vector> vecs;
		std::vector<Triangle> trias;
		std::vector<Atom> atom;
		Molecule* mol;


		for(int i = 0; i < args.size(); ++i)
			if (args[i].arg.size() >= 3)
			{
				double d1 = stod(args[i].arg[0]);
				double d2 = stod(args[i].arg[1]);
				double d3 = stod(args[i].arg[2]);
			}

	}

}
