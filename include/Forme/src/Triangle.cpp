#include "Forme/Triangle.hpp"

namespace fm {

void Triangle::ecrire(std::ostream &os) const {
	os << "Triangle ";
	Forme::ecrire(os);
	os << p1->getId() << ' ' << p2->getId();
}

Triangle::Triangle(uint couleur, int x, int y, Point * _p1, Point * _p2) : Forme(couleur, x, y), p1(_p1), p2(_p2) {}

Triangle::Triangle(const Triangle & ori) : Triangle(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), &Point(ori.getP1()), &Point(ori.getP2())) {}

Triangle::Triangle(std::istream &is) : Forme(is) {
	size_t id_p1, id_p2;
	is >> id_p1;
	is >> id_p2;

	p1 = Point::getPointByID(id_p1);
	p2 = Point::getPointByID(id_p2);
}

Triangle::~Triangle() {}

}//namespace
