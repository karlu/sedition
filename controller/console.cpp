#include "console.h"

using namespace std;

namespace SpaceWitch
{
	Console::Console(): maxMsg(5){}

	void Console::logMsg(string msg)
	{
		while (msgs.size() >= maxMsg)
			msgs.pop();
		msgs.push(msg);
	}

	queue<string> Console::getLogs()
	{
		return msgs;
	}

}
