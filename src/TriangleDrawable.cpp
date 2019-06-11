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

TriangleD::TriangleD(std::istream & is) : Forme(is), Triangle(is), FormeD(is) {
	p1 = PointD::getPointD(getP1());
	p2 = PointD::getPointD(getP2());

	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	dist1 = getDistance(getAncre(), p1->getPoint());
	dist2 = getDistance(getAncre(), p2->getPoint());
	recalculate();
}

TriangleD::~TriangleD() {}

//isOver avec des Aires, il pourrai y avoir plus optimisé
bool TriangleD::isOver(int x, int y) const {
	sf::Vector2f posSouris(x, y);
	sf::Vector2f ancre(getAncre().getX(), getAncre().getY());
	sf::Vector2f p1(p1->getX(), p1->getY());
	sf::Vector2f p2(p2->getX(), p2->getY());

	float A = getArea(ancre, p1, p2);
	float A1 = getArea(posSouris, p1, p2);
	float A2 = getArea(ancre, posSouris, p2);
	float A3 = getArea(ancre, p1, posSouris);

	return ( (getAncreD().isOver(x, y)) || (A == A1 + A2 + A3));
}

void TriangleD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
	p1->dessiner(window);
	p2->dessiner(window);
}

void TriangleD::maj() {
	FormeD::maj();
	setPosP1(getAncre().getX()+dist1.x, getAncre().getY() + dist1.y);
	setPosP2(getAncre().getX()+dist2.x, getAncre().getY() + dist2.y);
	p1->update();
	p2->update();
	recalculate();
}

void TriangleD::recalculate() {
	dist1 = getDistance(getAncre(), p1->getPoint());
	dist2 = getDistance(getAncre(), p2->getPoint());
	Shape::update();
}

float TriangleD::getArea(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3) const {
	return float(abs((p1.x*(p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0));
}

std::size_t TriangleD::getPointCount() const {
	return 3;	//Trois sommet a un triangle
}

sf::Vector2f TriangleD::getPoint(std::size_t index) const {
	switch (index) {
	default:	//pour eviter le warning
	case 0: return sf::Vector2f(getAncre().getX(), getAncre().getY());	//Premier point, ancre
	case 1: return sf::Vector2f(getP1()->getX(), getP1()->getY());	//2eme point
	case 2: return sf::Vector2f(getP2()->getX(), getP2()->getY());	//3eme point
	}
}