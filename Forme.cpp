#include "Forme.hpp"

void Forme::ecrire(std::ostream & os) const {
	os << couleur << ' ' << ancre << ' ' << selected << ' ';
}

Forme::Forme(uint _couleur, uint x, uint y) : couleur(_couleur), ancre(x,y), selected(false) {}

Forme::Forme(const Forme &ori) : Forme(ori.couleur, ori.ancre.getX(), ori.ancre.getY()) {}

Forme::Forme(std::istream &is) {
	is >> couleur;
	Point ancre(is);
	is >> selected;
}

Forme::~Forme() {}

Forme * Forme::charger(std::istream & is) {
	std::string type;
	is >> type;
	std::cout << "type : " << type << std::endl;
	/*if (type == "Rectangle") return new Rectangle(is);
	else if (type == "Carre") return new Carre(is);
	else if (type == "Ellipse") return new Ellipse(is);*/
	
	throw std::range_error("Cette forme n'existe pas");
}

std::ostream & operator<<(std::ostream & os, const Forme &forme) {
	forme.ecrire(os);
	return os;
}