#include "Forme/Carre.hpp"

namespace fm {

void Carre::ecrire(std::ostream &os) const {
	os << "Carre ";
	Forme::ecrire(os);
	os << cote << ' ';
}

Carre::Carre(uint couleur, uint x, uint y, uint _cote) : Forme(couleur, x, y), cote(_cote) {}

Carre::Carre(const Carre & ori) : Carre(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.cote) {}

Carre::Carre(std::istream &is) : Forme(is) {
	is >> cote;
}

Carre::~Carre() {}

}//namespace
