#ifndef ATOM_H
#define ATOM_H

#include "triangle.h"

#include <vector>

namespace SpaceWitch
{
	class Atom
	{
	public:
		void addTriangle(Triangle* t);
		Triangle* getTriangle(int i) const { return (triangle.at(i)); };
		int nTriangles() const { return triangle.size(); }

	private:
		std::vector<Triangle*> triangle;
	};

}

#endif
