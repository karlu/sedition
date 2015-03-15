#ifndef CAMERA_H
#define CAMERA_H

#include "actor.h"

namespace SpaceWitch
{
	class Camera
	{
	
	private:
		bool upBias;
		Actor* actor;

	public:
		double vib, bias, camDist;
		Camera(Actor* a);
		double applyBias();
		void move(double time);
	};
}

#endif
