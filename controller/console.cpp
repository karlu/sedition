#include "console.h"

namespace SpaceWitch
{
	Console::Console(): maxMsgs(5){}

	void Console::logMsg(string msg)
	{
		while (msgs.size() >= maxMsg)
			msgs.pop();
		msgs.push(msg);
	}

	queue Console::getLogs()
	{
		return msgs
	}

}
