#include "Ellipse.hpp"

Ellipse::Ellipse(ulong couleur, uint x, uint y, uint _demiLargeur, uint _demiHauteur) : Forme(couleur,x,y), demiLargeur(_demiLargeur), demiHauteur(_demiHauteur) {}

Ellipse::Ellipse(const Ellipse & ori) : Ellipse(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.demiLargeur, ori.demiHauteur) {}

Ellipse::Ellipse(std::istream & is) {
	is >> demiLargeur;
	is >> demiHauteur;
}

Ellipse::~Ellipse() {}


void Ellipse::dessiner(EZWindow & fenetre, bool active) const {
    Forme::dessiner(fenetre, active);
    fenetre.drawCircle(getAncre().getX(), getAncre().getY(), getAncre().getX()+demiLargeur, getAncre().getY()+demiHauteur);
}

bool Ellipse::isOver(uint _x, uint _y) const
{
	return ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + demiLargeur) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + demiHauteur));
}