#include "Calque.hpp"

Calque::Calque(bool _active) : active(_active) {
	tab_forme = new std::vector<FormeD*>;
	tab_point = new std::vector<PointD*>;
}

Calque::~Calque() {
	delete tab_forme;
}

void Calque::ajouter(FormeD * shape) {
	tab_forme->push_back(shape);
}

void Calque::ajouter(PointD * point) {
	tab_point->push_back(point);
}

FormeD* Calque::isOverForme(int x, int y) const {
	for (size_t i = 0; i < tab_forme->size(); i++) {
		if (tab_forme->at(i)->isOver(x, y)) return tab_forme->at(i);
	}
	return nullptr;
}

PointD* Calque::isOverPoint(int x, int y) const {
	for (size_t i = 0; i < tab_point->size(); i++) {
		if (tab_point->at(i)->isOver(x, y)) return tab_point->at(i);
	}
	return nullptr;
}


void Calque::dessiner(sf::RenderWindow & window) const {
	for (size_t i = tab_forme->size()-1; i >= 0 && i < tab_forme->size(); i--) tab_forme->at(i)->dessiner(window);
	for (size_t i = tab_point->size()-1; i >= 0 && i < tab_point->size(); i--) tab_point->at(i)->dessiner(window);
}

Calque * Calque::charger(std::istream & is) {
	//TODO
	return nullptr;
}

std::ostream & operator<<(std::ostream & os, const Calque & calque) {
	//TODO
	os << "TODO";
	return os;
}
