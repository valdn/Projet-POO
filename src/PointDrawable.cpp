#include "PointDrawable.hpp"

PointD::PointD(fm::Point * _point, sf::Color _couleur) : point(_point), couleur(_couleur) {
	cercle.setFillColor(couleur);
	cercle.setRadius((float)point->getTaille());
	cercle.setOrigin(cercle.getRadius(), cercle.getRadius());
	update();
}

PointD::PointD(int x, int y, sf::Color _couleur) : point(new fm::Point(x,y)), couleur(_couleur) {
	cercle.setFillColor(couleur);
	cercle.setRadius((float)point->getTaille());
	cercle.setOrigin(cercle.getRadius(), cercle.getRadius());
	update();
}

PointD::PointD(const PointD & ori) : PointD(&fm::Point(ori.getPoint()), ori.couleur) {}

PointD::~PointD() {
	point = nullptr;
}

void PointD::update() {
	cercle.setPosition((float)point->getX(), (float)point->getY());
}

void PointD::dessiner(sf::RenderWindow & window) const {
	window.draw(cercle);
}

bool PointD::isOver(int x, int y) const {
	//retourne vrai si la distance entre le centre du cerlce et la souris est inf�rieur au rayon
	return ((std::pow(x - point->getX(), 2) + std::pow(y - point->getY(), 2)) <= std::pow(point->getTaille(),2));
}

PointD * PointD::charger(std::istream & is) {
	return new PointD(new fm::Point(is));
}

std::ostream & operator<<(std::ostream & os, const PointD & p) {
	os << p.getPoint();
	os << p.couleur.toInteger();
	return os;
}
