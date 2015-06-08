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
		void logMsg(std::string);
		std::queue<std::string> getLogs();

	private:
		int maxMsg;
		std::queue<std::string> msgs;
	};

}


#endif
