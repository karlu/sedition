#ifndef MOLECULE_H
#define MOLECULE_H

#include "atom.h"

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
