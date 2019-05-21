#include "Forme/Rectangle.hpp"

namespace fm {

void Rectangle::ecrire(std::ostream &os) const {
	os << "Rectangle ";
	Forme::ecrire(os);
	os << largeur << ' ' << hauteur;
}

Rectangle::Rectangle(uint couleur, int x, int y, uint _largeur, uint _hauteur) : Forme(couleur, x, y), largeur(_largeur), hauteur(_hauteur) {}

Rectangle::Rectangle(const Rectangle & ori) : Rectangle(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.largeur, ori.hauteur) {}

Rectangle::Rectangle(std::istream &is) : Forme(is) {
	is >> largeur;
	is >> hauteur;
}

Rectangle::~Rectangle() {}

}//namespace