#include "Cercle.hpp"

void Cercle::ecrire(std::ostream &os) const {
	os << "Cercle ";
	Forme::ecrire(os);
	os << rayon << ' ';
}

Cercle::Cercle(ulong couleur, uint x, uint y, uint _rayon) : Forme(couleur, x, y), rayon(_rayon) {}

Cercle::Cercle(const Cercle & ori) : Cercle(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.rayon) {}

Cercle::Cercle(std::istream & is) : Forme(is) {
	is >> rayon;
}

Cercle::~Cercle() {}


void Cercle::dessiner(EZWindow & fenetre, bool active) const {
	Forme::dessiner(fenetre, active);
	fenetre.drawCircle(getAncre().getX(), getAncre().getY(), getAncre().getX() + rayon, getAncre().getY() + rayon);
}

bool Cercle::isOver(uint _x, uint _y) const
{
	return ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + rayon) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + rayon));
}