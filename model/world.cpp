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

	void World::eval()
	{
		double currentTime=0; // get current time
		for(int i=0; i<actor.size(); ++i)
			actor.move(1); // currentTime-lastUpdated
		lastUpdated=currentTime;
	}
}
