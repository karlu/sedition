#include "world.h"

namespace SpaceWitch
{
	World::World(double currentTime)
	{
		lastUpdated=currentTime;
	}

	void World::addActor(Actor* t)
	{
		actor.push_back(t);
	}

	void World::eval(double currentTime)
	{
		double timeDiff = currentTime-lastUpdated;
		if(timeDiff < 0)
			timeDiff = 40.0;
		for(int i=0; i<actor.size(); ++i)
			actor.at(i)->move(timeDiff);
		lastUpdated=currentTime;
	}
}
