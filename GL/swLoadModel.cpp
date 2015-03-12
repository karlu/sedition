#include "swLoadModel.h"

#include <fstream>

//#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace SpaceWitch
{
	void readstr(FILE *f, char *string)
	{
		do
		{
			fgets(string, 255, f);
		} while ((string[0] == '/') || (string[0] == '\n'));
		return;
	}
	
	void scrapComments(string &oneline)
	{
		int pos = oneline.find('#');
		if (pos >= 0)
			oneline.erase(pos, oneline.size());
	}

	void createToken(vector<string> &tokens, string &t)
	{
		if (!t.empty())
		{
			tokens.push_back(t);
			t = "";
		}
	}

	void tokenize(vector<string> &tokens, const string &oneline)
	{
		string tmp = "";
		for (int i = 0; i<oneline.length(); ++i)
		{
			if (oneline[i] != ' ' && oneline[i] != '\t')
				tmp += oneline[i];
			else
				createToken(tokens, tmp);
		}
		createToken(tokens, tmp);
	}

	int createVertex(Vector &v, vector<string> &tokens)
	{
		try
		{
			int d1 = stod(tokens.at(0));
			int d2 = stod(tokens.at(1));
			int d3 = stod(tokens.at(2));
			v = Vector(d1, d2, d3);
		}
		catch (const invalid_argument &ia)
		{
			//cerr << "Expected double, didnt get such\n";
			return -1;
		}

		return 1;
	}

	void interpretTokens(vector<Vector> &vectorList, vector<string> &tokens)
	{
		if (0 == tokens.size())
			return;
		if (3 == tokens.size())
		{
			Vector v;
			if (createVertex(v, tokens) > 0);
			{
				vectorList.push_back(v);
			}
		}
	}

	int readFromFile(vector<Vector> &vectorList)
	{
		string oneline;
		ifstream F("file.txt");

		if (F.is_open())
		{
			while (getline(F, oneline))
			{
				scrapComments(oneline);
				vector<string> tokens;
				tokenize(tokens, oneline);
				interpretTokens(vectorList, tokens);
			}
		}
	}

	void setupModel()
	{
		vector<Vector> vectorList;
		readFromFile(vectorList);
	}

	/*
	Atom SetupModel(char *adrs, Atom sector)
	{
		float x, y, z, u, v;
		int t;
		int numtriangles;
		FILE *filein;
		char oneline[255];

		/*
		 * WINDOWS SPECIAL LANGUAGE ALERT!
		 * fopen_s is not GNU
		 * USE fopen INSTEAD
		 * Should be
		 * filein = fopen(adrs, "rt");
		 * /

		// Is
		fopen_s(&filein, adrs, "rt");

		// Normal code
		readstr(filein, oneline);

		// Is
		sscanf_s("%255s", oneline, "NUMPOLLIES %d\n", &numtriangles);

		/*
		 * Should be
		 * sscanf(oneline, "NUMPOLLIES %d\n", &numtriangles);
		 * END OF
		 * WINDOWS SPECIAL LANGUAGE ALERT!
		 * /

		

		for (int loop = 0; loop < numtriangles; loop++)
		{
			readstr(filein, oneline);
			sscanf(oneline, "%d", &t);
			
			Vector tmpVec[3];

			for (int vert = 0; vert < 3; vert++)
			{
				readstr(filein, oneline);
				sscanf(oneline, "%f %f %f %f %f", &x, &y, &z, &u, &v);
				tmpVec[vert] = Vector(x, y, z);
			}

			Triangle* tmpTri = new Triangle(tmpVec[0], tmpVec[1], tmpVec[2]);
			sector.addTriangle(tmpTri);
		}
		fclose(filein);
		return sector;
	}
	*/

}