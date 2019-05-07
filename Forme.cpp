#include "Forme.hpp"
#include "Rectangle.hpp"

void Forme::ecrire(std::ostream & os) const {
	os << couleur << ' ' << ancre << ' ';
}

Forme::Forme() : couleur(NULL), ancre(NULL, NULL), selected(false) {};

Forme::Forme(const ulong _couleur, uint x, uint y) : couleur(_couleur), ancre(x,y), selected(false) {}

Forme::Forme(const Forme &ori) : Forme(ori.couleur, ori.ancre.getX(), ori.ancre.getY()) {}

Forme::Forme(std::istream &is) {
	is >> couleur;
	ancre = Point::Point(is);
	is >> selected;
}

Forme::~Forme() {}

//bool Forme::isOver(uint x, uint y) const {
//	return (getAncre().isOver(x,y));
//}


void Forme::dessiner(EZWindow & fenetre, bool active) const{
    fenetre.setColor(ez_black);
    ancre.dessiner(fenetre, active);
    fenetre.setColor(couleur);
}

Forme * Forme::charger(std::istream & is) {
	std::string type;
	is >> type;
	if (type == "Rectangle") return new Rectangle(is);
	throw std::range_error("Cette forme n'existe pas");
}

std::ostream & operator<<(std::ostream & os, const Forme &forme) {
	forme.ecrire(os);
	return os;
}
