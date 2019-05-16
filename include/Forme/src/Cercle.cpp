#include "Forme/Cercle.hpp"

namespace fm {

void Cercle::ecrire(std::ostream &os) const {
	os << "Cercle ";
	Forme::ecrire(os);
	os << rayon << ' ';
}

Cercle::Cercle(uint couleur, int x, int y, uint _rayon) : Forme(couleur, x, y), rayon(_rayon) {}

Cercle::Cercle(const Cercle & ori) : Cercle(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.rayon) {}

Cercle::Cercle(std::istream &is) : Forme(is) {
	is >> rayon;
}

Cercle::~Cercle() {}

}//namespace