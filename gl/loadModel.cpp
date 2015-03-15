#include "loadModel.h"

#include <fstream>

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
		int d1 = stod(tokens.at(0));
		int d2 = stod(tokens.at(1));
		int d3 = stod(tokens.at(2));
		v = Vector(d1, d2, d3);

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
}
