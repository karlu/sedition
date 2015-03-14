#ifndef SWMOLECULE_H
#define SWMOLECULE_H

#include "swAtom.h"

#include <vector>

namespace SpaceWitch
{
	class Molecule
	{
	public:
		void addAtom(Atom* t);
		Atom* getAtom(int i) const { return (atom.at(i)); };
		int nAtoms() const { return atom.size(); }

	private:
		std::vector<Atom*> atom;
	};

}

#endif
