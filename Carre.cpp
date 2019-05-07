#include "Carre.hpp"


void Carre::ecrire(std::ostream &os) const {
	os << "Carre ";
	Forme::ecrire(os);
	os << cote << ' ';
}

Carre::Carre(ulong couleur, uint x, uint y, uint _cote) : Forme(couleur, x, y), cote(_cote) {}

Carre::Carre(const Carre & ori) : Carre(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.cote) {}

Carre::Carre(std::istream &is) : Forme(is) {
	is >> cote;
}

Carre::~Carre() {}

void Carre::dessiner(EZWindow & fenetre, bool active) const {
	Forme::dessiner(fenetre, active);
	fenetre.drawRectangle(getAncre().getX(), getAncre().getY(), getAncre().getX() + cote, getAncre().getY() + cote);
}

bool Carre::isOver(uint _x, uint _y) const
{
	return ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + cote) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + cote));
}
