#include "Forme/Ellipse.hpp"

namespace fm {

void Ellipse::ecrire(std::ostream &os) const {
	os << "Ellipse ";
	Forme::ecrire(os);
	os << demiLargeur << ' ' << demiHauteur;
}

Ellipse::Ellipse(uint couleur, uint x, uint y, uint _demiLargeur, uint _demiHauteur) : Forme(couleur, _demiLargeur + x, _demiHauteur + y), demiLargeur(_demiLargeur), demiHauteur(_demiHauteur) {}

Ellipse::Ellipse(const Ellipse & ori) : Ellipse(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.demiLargeur, ori.demiHauteur) {}

Ellipse::Ellipse(std::istream &is) : Forme(is) {
	is >> demiLargeur;
	is >> demiHauteur;
}

Ellipse::~Ellipse() {}

}	//namespace