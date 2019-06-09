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

void Calque::supprimer(FormeD * shape) {
	try {
		tab_forme->erase(tab_forme->begin() + getPosShape(shape));
	}
	catch (std::domain_error & e) {
		std::cerr << e.what() << std::endl;
	}
	
}

void Calque::supprimer(PointD * point) {
	try {
		tab_point->erase(tab_point->begin() + getPosPoint(point));
	}
	catch (std::domain_error & e) {
		std::cerr << e.what() << std::endl;
	}
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

bool Calque::isInTab(FormeD * shape) const {
	for (size_t i = 0; i < tab_forme->size(); i++) {
		if (tab_forme->at(i) == shape)
			return true;
	}
	return false;
}

bool Calque::isInTab(PointD * point) const {
	for (size_t i = 0; i < tab_point->size(); i++) {
		if (tab_point->at(i) == point)
			return true;
	}
	return false;
}

size_t Calque::getPosShape(FormeD * shape) const {
	for (size_t i = 0; i < tab_forme->size(); ++i) {
		if (tab_forme->at(i) == shape) return i;
	}
	throw std::domain_error("La forme n'est pas dans ce calque");
}

size_t Calque::getPosPoint(PointD * point) const {
	for (size_t i = 0; i < tab_point->size(); ++i) {
		if (tab_point->at(i) == point) return i;
	}
	throw std::domain_error("Le point n'est pas dans ce calque");
}

std::ostream & operator<<(std::ostream & os, const Calque & calque) {
	//TODO
	return os;
}
