#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <queue>

namespace SpaceWitch
{
	class Console
	{
	public:
		Console();
		void logMsg(string);
		queue<string> getLogs();

	private:
		int maxMsg;
		queue<string> msgs
	}

}


#endif
