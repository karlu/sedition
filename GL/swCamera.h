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
		double vib, bias;
		Camera(Actor* a);
		double bias();
		void move(double time);
	};
}

#endif