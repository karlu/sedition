#ifndef SWCAMERA_H
#define SWCAMERA_H

#include "swActor.h"

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
