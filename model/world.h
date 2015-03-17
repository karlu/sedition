#ifndef WORLD_H
#define WORLD_H

#include "actor.h"

#include <vector>

namespace SpaceWitch
{
	class World
	{
	public:
		World(double);
		void addActor(Actor* t);
		Actor* getActor(int i) const { return (actor.at(i)); };
		int nActors() const { return actor.size(); }
		void eval();

	private:
		double lastUpdated;
		std::vector<Actor*> actor;
	};

}

#endif
