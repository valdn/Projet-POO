#include "Groupe.hpp"

Groupe::Groupe() {
	tab_forme = new std::vector<FormeD*>;
}

Groupe::~Groupe() {
	delete tab_forme;
}

void Groupe::ajouter(FormeD * forme) {
	if (tab_forme->size() >= tab_forme->max_size()) throw std::runtime_error("Vecteur de forme complet");
	else tab_forme->push_back(forme);
}

void Groupe::supprimer(FormeD * shape)
{
	for (size_t i = 0; i < tab_forme->size(); i++) {
		if (tab_forme->at(i) == shape)
			tab_forme->erase(tab_forme->begin()+i);
	}
}


void Groupe::update() const {
	for (size_t i = 0; i < tab_forme->size(); i++) tab_forme->at(i)->recalculate();
}

void Groupe::deplacer(int x, int y) const {
	for (size_t i = 0; i < tab_forme->size(); i++) {
		if (tab_forme->at(i) != nullptr) {
			tab_forme->at(i)->setAncre(tab_forme->at(i)->getAncre().getX() + x, tab_forme->at(i)->getAncre().getY() + y);
			tab_forme->at(i)->maj();
		}
	}
}

bool Groupe::inTab(FormeD * shape) const {
	for (size_t i = 0; i < tab_forme->size(); i++) {
		if (tab_forme->at(i) == shape)
			return true;
	}
	return false;
}

