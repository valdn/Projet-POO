#include "Rectangle.hpp"


void Rectangle::ecrire(std::ostream &os) const {
	os << "Rectangle ";
	Forme::ecrire(os);
	os << largeur << ' ' << hauteur;
}

Rectangle::Rectangle(ulong couleur, uint x, uint y, uint _largeur, uint _hauteur) : Forme(couleur,x,y), largeur(_largeur), hauteur(_hauteur) {}

Rectangle::Rectangle(const Rectangle & ori) : Rectangle(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.largeur, ori.hauteur) {}

Rectangle::Rectangle(std::istream &is) : Forme(is) {
	is >> largeur;
	is >> hauteur;;
}

Rectangle::~Rectangle() {}

void Rectangle::dessiner(EZWindow & fenetre, bool active) const {
    Forme::dessiner(fenetre, active);
    fenetre.drawRectangle(getAncre().getX(), getAncre().getY(), getAncre().getX()+largeur, getAncre().getY()+hauteur);
}

bool Rectangle::isOver(uint _x, uint _y) const
{
	return ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + largeur) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + hauteur));
}
