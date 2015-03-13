#include "swCamera.h"

namespace SpaceWitch
{
	Camera::Camera(Actor* a)
	{
		camDist	=2.0f;
		actor = a;
		vib = bias = 0;
	}

	double Camera::bias()
	{
		if(upBias)
		{
			if(bias<0.004)
				bias += 0.0001;
			else
			{
				upBias = false;
				bias -= 0.0001;
			}
		}

		else
		{
			if(bias>-0.004)
				bias -= 0.0001;
			else
			{
				upBias = true;
				bias += 0.0001;
			}
		}
		return bias;
	}

}