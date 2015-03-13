#ifndef SWACTOR_H
#define SWACTOR_H

#include "swMatrix.h"
#include "swAtom.h"



namespace SpaceWitch
{
	struct ActorCommands
	{
		bool FORWARD, BACKWARD, RIGHT, LEFT, PITCHUP, PITCHDOWN, ROLLUP, ROLLDOWN;
	};

	const double SPEED_CONSTANT = 0.01;
	
	class Actor
	{
	public:
		ActorCommands commands;
		Atom model;
		Actor();
		void move(double time);
		
		Vector getPosition() const { return pos; }
		Vector &getDirection(Vector &res) const;
		Vector &getTop(Vector &res) const;
		Vector &rotVector(Vector &res, Vector &v) const;

	private:
		Vector &getDeltaRot(Vector &res, double time) const;
		void accelerate(double time);
		void resetCommands();
		
		Vector pos;
		Vector speed;
		Matrix dir;
	};
}

#endif