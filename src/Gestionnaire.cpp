#include "Gestionnaire.hpp"

Gestionnaire::Gestionnaire() {
	tab_calque.push_back(new Calque());	//Calque de base 
}

Gestionnaire::~Gestionnaire() {
	//D�truit toutes les formes
	for (size_t i = 0; i < tab_forme.size(); i++) {
		delete tab_forme[i];
	}
	tab_forme.clear();

	//D�truit tous les points
	for (size_t i = 0; i < tab_point.size(); i++) {
		delete tab_point[i];
	}
	tab_point.clear();

	//D�truit tous les calques
	for (size_t i = 0; i < tab_calque.size(); i++) {
		delete tab_calque[i];
	}
	tab_calque.clear();

	//D�truit tous les groupes
	for (size_t i = 0; i < tab_groupe.size(); i++) {
		delete tab_groupe[i];
	}
	tab_groupe.clear();
}

void Gestionnaire::ajouter(FormeD * forme, size_t num_calque) {
	if (tab_forme.size() >= tab_forme.max_size()) throw std::runtime_error("Vecteur de forme complet");
	else {
		tab_forme.push_back(forme);
		try {
			tab_calque.at(num_calque)->ajouter(forme);
		}
		catch (std::out_of_range & e) {
			std::cerr << "Le calque " << num_calque << " n'existe pas !" << std::endl;
		}
	}
}

void Gestionnaire::ajouter(PointD * point, size_t num_calque) {
	if (tab_point.size() >= tab_point.max_size()) throw std::runtime_error("Vecteur de point complet");
	else {
		tab_point.push_back(point);
		try {
			tab_calque.at(num_calque)->ajouter(point);
		} catch (std::out_of_range & e) {
			std::cerr << "Le calque " << num_calque << " n'existe pas !" << std::endl;
		}
	}
}

void Gestionnaire::ajouter(Calque * calque) {
	if (tab_calque.size() >= tab_calque.max_size()) throw std::runtime_error("Vecteur de calque complet");
	else tab_calque.push_back(calque);
}

void Gestionnaire::ajouter(Groupe * groupe) {
	if (tab_groupe.size() >= tab_groupe.max_size()) throw std::runtime_error("Vecteur de groupe complet");
	else tab_groupe.push_back(groupe);
}

void Gestionnaire::sauver(std::ostream & os) const {
	//Sauvegarde les points
	os << tab_point.size() << std::endl;
	for (size_t i = 0; i < tab_point.size(); i++) os << (*tab_point[i]) << std::endl;

	os << std::endl;
	//Sauvegarde les formes
	os << tab_forme.size() << std::endl;
	for (size_t i = 0; i < tab_forme.size(); i++) os << (*tab_forme[i]) << std::endl;

	os << std::endl;
	//Sauvegarde les calques
	os << tab_calque.size() << std::endl;
	for (size_t i = 0; i < tab_calque.size(); i++) os << (*tab_calque[i]) << std::endl;
}

void Gestionnaire::charger(std::istream & is) {
	//Remet tout a zero
	for (size_t i = 0; i < tab_forme.size(); i++) delete tab_forme[i];
	tab_forme.clear();
	for (size_t i = 0; i < tab_point.size(); i++) delete tab_point[i];
	tab_point.clear();
	for (size_t i = 0; i < tab_calque.size(); i++) delete tab_calque[i];
	tab_calque.clear();

	//Charge les points
	size_t nb;
	is >> nb;
	for (size_t i = 0; i < nb; ++i) {
		try {
			ajouter(PointD::charger(is));
		} catch (std::runtime_error & e) {
			std::cerr << e.what() << std::endl;
		}
	}

	//Charge les formes
	is >> nb;
	for (size_t i = 0; i < nb; ++i) {
		try {
			ajouter(FormeD::charger(is));
		}
		catch (std::runtime_error & e) {
			std::cerr << e.what() << std::endl;
		}
	}

	//Charge les calques
	is >> nb;
	for (size_t i = 0; i < nb; ++i) {
		try {
			ajouter(Calque::charger(is));
		}
		catch (std::runtime_error & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void Gestionnaire::update() const {
	for (size_t i = 0; i < tab_forme.size(); i++) tab_forme[i]->recalculate();
}

void Gestionnaire::dessiner(sf::RenderWindow & window) const {
	for (size_t i = 0; i < tab_calque.size(); i++) {
		if (tab_calque[i]->isActive()) {
			tab_calque[i]->dessiner(window);
		}
	}
}

void Gestionnaire::addToGroup(Groupe * g1, Groupe * g2) {
	for (size_t i = 0; i < g1->getNbFormes();) {
		g2->ajouter(g1->getFormeAt(i));
		g1->supprimer(g1->getFormeAt(i));
	}
}

ImageD * Gestionnaire::getImageByPoint(PointD * p1) const {
	for (size_t i = 0; i < tab_forme.size(); i++) {
		ImageD * test = dynamic_cast<ImageD*> (tab_forme[i]);
		if (test != nullptr && test->getPointD() == p1) return test;
	}
	return nullptr;
}

FormeD * Gestionnaire::isOverForme(int x, int y) const {
	for (size_t i = tab_calque.size() - 1; i >= 0 && i < tab_calque.size(); i--) {
		FormeD* forme = tab_calque[i]->isOverForme(x, y);
		if (forme != nullptr)
			return forme;
	}
	return nullptr;
}

PointD * Gestionnaire::isOverPoint(int x, int y) const {
	for (size_t i = tab_calque.size() - 1; i >= 0 && i < tab_calque.size(); i--) {
		PointD * point = tab_calque[i]->isOverPoint(x, y);
		if (point != nullptr)
			return point;
	}
	return nullptr;
}


Groupe * Gestionnaire::getGroupe(FormeD * shape) const
{
	for (size_t i = 0; i  < tab_groupe.size(); i++) {
		if (tab_groupe[i]->inTab(shape)) return tab_groupe[i];
	}
	return nullptr;
}