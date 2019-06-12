#include "Forme/Forme.hpp"
#include "Forme/Rectangle.hpp"
#include "Forme/Carre.hpp"
#include "Forme/Ellipse.hpp"
#include "Forme/Cercle.hpp"
#include "Forme/Triangle.hpp"
#include "Forme/Polygone.hpp"


namespace fm {

void Forme::ecrire(std::ostream & os) const {
	os << ancre << ' ' << couleur << ' ';
}

Forme::Forme(uint _couleur, int x, int y) : couleur(_couleur), ancre(x, y) {}

Forme::Forme(const Forme &ori) : Forme(ori.couleur, ori.ancre.getX(), ori.ancre.getY()) {}

Forme::Forme(std::istream &is) : ancre(is) {
	is >> couleur;
}

Forme::~Forme() {}

bool Forme::pointInShape(const Point * point) const {
	if (point == &ancre) return true;
	else return false;
}

double Forme::getLonSeg(const Point p1, const Point p2) const {
	return std::sqrt(std::pow(p2.getX() - p1.getX(), 2) + std::pow(p2.getY() - p1.getY(), 2));
}

Forme * Forme::charger(std::istream & is) {
	std::string type;
	is >> type;
	if (type == "Rectangle") return new Rectangle(is);
	else if (type == "Carre") return new Carre(is);
	else if (type == "Ellipse") return new Ellipse(is);
	else if (type == "Cercle") return new Cercle(is);
	else if (type == "Triangle") return new Triangle(is);
	else if (type == "Polygone") return new Polygone(is);

	throw std::range_error("La forme \"" + type + "\" n'existe pas");
}

std::ostream & operator<<(std::ostream & os, const Forme &forme) {
	forme.ecrire(os);
	return os;
}

}//namespace