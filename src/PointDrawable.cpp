#include "PointDrawable.hpp"

std::vector<PointD*> PointD::tab_points = std::vector<PointD*>();

PointD::PointD(fm::Point * _point, sf::Color _couleur, bool _partage) : point(_point), couleur(_couleur), partage(_partage) {
	tab_points.push_back(this);
	cercle.setFillColor(couleur);
	cercle.setRadius((float)point->getTaille());
	cercle.setOrigin(cercle.getRadius(), cercle.getRadius());
	update();
}

PointD::PointD(int x, int y, bool _partage, sf::Color _couleur) : point(new fm::Point(x,y)), couleur(_couleur), partage(_partage) {
	tab_points.push_back(this);
	cercle.setFillColor(couleur);
	cercle.setRadius((float)point->getTaille());
	cercle.setOrigin(cercle.getRadius(), cercle.getRadius());
	update();
}

PointD::PointD(const PointD & ori) : PointD(&fm::Point(ori.getPoint()), ori.couleur) {}

PointD::PointD(std::istream & is) : point(new fm::Point(is)) {
	is >> partage;
	tab_points.push_back(this);
	cercle.setFillColor(couleur);
	cercle.setRadius((float)point->getTaille());
	cercle.setOrigin(cercle.getRadius(), cercle.getRadius());
	update();
}

PointD::~PointD() {
	try { 
		tab_points.erase(tab_points.begin() + getPointDIndex(this)); 
	}
	catch (std::domain_error & e) {
		std::cerr << e.what() << std::endl;
	}
	
	if (partage) delete point;

	point = nullptr;
}

void PointD::setColor(sf::Color _couleur) {
	couleur = _couleur;
	cercle.setFillColor(couleur);
	update();
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
	return new PointD(is);
}

PointD * PointD::getPointD(const fm::Point * point) {
	for (size_t i = 0; i < tab_points.size(); ++i) {
		if (tab_points[i]->getPtrPoint() == point) return tab_points[i];
	}
	return nullptr;
}

size_t PointD::getPointDIndex(PointD * point) {
	for (size_t i = 0; tab_points.size(); ++i) {
		if (tab_points[i] == point) return i;
	}

	throw std::domain_error("Le point n'existe pas");
}

std::ostream & operator<<(std::ostream & os, const PointD & p) {
	os << p.getPoint() << ' ' << p.partage;
	return os;
}
