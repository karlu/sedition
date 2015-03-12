#include "swTriangle.h"

namespace SpaceWitch
{
	Triangle::Triangle(Vector &v1, Vector &v2, Vector &v3)
	{
		v[0] = v1;
		v[1] = v2;
		v[2] = v3;
	}
}