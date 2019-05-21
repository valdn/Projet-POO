#include "TriangleDrawable.hpp"

TriangleD::TriangleD(sf::Color couleur, int x1, int y1, PointD * _p1, PointD * _p2)
	: Forme(couleur.toInteger(), x1, y1),
		Triangle(couleur.toInteger(), x1, y1, _p1->getPtrPoint(), _p2->getPtrPoint()),
		FormeD(couleur, x1, y1),
		p1(_p1), p2(_p2)
{
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	dist1 = getDistance(getAncre(), p1->getPoint());
	dist2 = getDistance(getAncre(), p2->getPoint());
	recalculate();
}

TriangleD::TriangleD(const TriangleD & ori) : TriangleD(sf::Color(ori.getCouleur()), getAncre().getX(), getAncre().getY(), ori.p1, ori.p2) {}

TriangleD::TriangleD(std::istream & is) : Forme(is), Triangle(is), FormeD(is), p1(&PointD(getPtrP1())), p2(&PointD(getPtrP2())) {
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	dist1 = getDistance(getAncre(), p1->getPoint());
	dist2 = getDistance(getAncre(), p2->getPoint());
	recalculate();
}

TriangleD::~TriangleD() {}

//TODO
bool TriangleD::isOver(int x, int y) const {
	return (getAncreD().isOver(x,y));
}

void TriangleD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
	p1->dessiner(window);
	p2->dessiner(window);
}

void TriangleD::maj() {
	FormeD::maj();
	p1->getPtrPoint()->setXY(getAncre().getX()+dist1.x, getAncre().getY() + dist1.y);
	p2->getPtrPoint()->setXY(getAncre().getX()+dist2.x, getAncre().getY() + dist2.y);
	p1->update();
	p2->update();
	recalculate();
}

void TriangleD::recalculate() {
	dist1 = getDistance(getAncre(), p1->getPoint());
	dist2 = getDistance(getAncre(), p2->getPoint());
	Shape::update();
}

std::size_t TriangleD::getPointCount() const {
	return 3;	//Trois sommet a un triangle
}

sf::Vector2f TriangleD::getPoint(std::size_t index) const {
	switch (index) {
	default:	//pour eviter le warning
	case 0: return sf::Vector2f(getAncre().getX(), getAncre().getY());	//Premier point, ancre
	case 1: return sf::Vector2f(getP1().getX(), getP1().getY());	//2eme point
	case 2: return sf::Vector2f(getP2().getX(), getP2().getY());	//3eme point
	}
}