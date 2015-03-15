#include "commonMath.h"
#include "actor.h"

namespace SpaceWitch
{
	Actor::Actor()
	{
		pos = Vector();
		speed = Vector();
		dir	= Matrix();
	}

	void Actor::move(double time)
	{
		Vector deltaRot;
		dir.Rot(getDeltaRot(deltaRot,time));
		accelerate(time);
		pos += speed;
		resetCommands();
	}

	Vector &Actor::getDirection(Vector &res) const
	{
		res = Vector(dir(0, 2), dir(1, 2), dir(2, 2));
		return res;
	}

	Vector &Actor::getTop(Vector &res) const
	{
		res = Vector(dir(0, 1), dir(1, 1), dir(2, 1));
		return res;
	}

	Vector &Actor::rotVector(Vector &res, Vector &v) const
	{
		res = dir*v;
		return res;
	}

	Vector &Actor::getDeltaRot(Vector &res, double time) const
	{
		res = Vector(
			(commands.PITCHUP - commands.PITCHDOWN) * time * SPEED_CONSTANT,
			(commands.RIGHT - commands.LEFT) * time * SPEED_CONSTANT,
			(commands.ROLLUP - commands.ROLLDOWN) * time * SPEED_CONSTANT);
		return res;
	}

	void Actor::accelerate(double time)
	{
		Vector direction;
		getDirection(direction);
		speed += direction * time * (commands.FORWARD - commands.BACKWARD);
		if (speed.magSqr() < 0.001)
			speed.reset();
		else
			speed *= 0.1*time;
	}

	void Actor::resetCommands()
	{
		commands = { false, false, false, false, false, false, false, false };
	}

}
