#ifndef SWTRIANGLE_H
#define SWTRIANGLE_H

#include "vector.h"

namespace SpaceWitch
{
	class Triangle
	{
	public:
		Triangle(Vector &v1, Vector &v2, Vector &v3);
		Vector v[3];
	};
}

#endif
