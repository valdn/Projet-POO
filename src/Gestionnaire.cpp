#include "Gestionnaire.hpp"

Gestionnaire::Gestionnaire() {
	tab_calque.push_back(new Calque());	//Calque de base 
	tab_groupe.push_back(new Groupe()); //Groupe par défaut
}

Gestionnaire::~Gestionnaire() {
	//Détruit toutes les formes
	for (size_t i = 0; i < tab_forme.size(); i++) {
		delete tab_forme[i];
	}
	tab_forme.clear();

	//Détruit tous les points
	for (size_t i = 0; i < tab_point.size(); i++) {
		delete tab_point[i];
	}
	tab_point.clear();

	//Détruit tous les calques
	for (size_t i = 0; i < tab_calque.size(); i++) {
		delete tab_calque[i];
	}
	tab_calque.clear();

	//Détruit tous les groupes
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

void Gestionnaire::supprimer(FormeD * forme) {
	for (size_t i = 0; i < tab_calque.size(); ++i) {
		if (tab_calque[i]->isInTab(forme)) tab_calque[i]->supprimer(forme);
	}

	try {
		tab_forme.erase(tab_forme.begin() + getIndex(forme));
	}
	catch (std::domain_error & e) {
		std::cerr << e.what() << std::endl;
	}
}

void Gestionnaire::supprimer(PointD * point) {
	for (size_t i = 0; i < tab_calque.size(); ++i) {
		if (tab_calque[i]->isInTab(point)) tab_calque[i]->supprimer(point);
	}

	try {
		tab_point.erase(tab_point.begin() + getIndex(point));
	}
	catch (std::domain_error & e) {
		std::cerr << e.what() << std::endl;
	}
}

void Gestionnaire::supprimer(size_t icalque) {
	Calque * calque = tab_calque.at(icalque);
	for (size_t i = 0; i < calque->getNbFormes();) {
		supprimer(calque->getFormeAt(i));
	}

	for (size_t i = 0; i < calque->getNbPoints();) {
		supprimer(calque->getPointAt(i));
	}

	supprimer(calque);
}

void Gestionnaire::supprimer(Calque * calque) {
	if (tab_calque.size() > 1)	tab_calque.erase(tab_calque.begin() + getIndex(calque));
}

void Gestionnaire::supprimer(Groupe * groupe) {
	for (size_t i = 0; i < groupe->getNbFormes();) {
		supprimer(groupe->getFormeAt(i));
		groupe->supprimer(groupe->getFormeAt(i));
	}
}

void Gestionnaire::sauver(std::ostream & os) const {

	//Sauvegarde le nombre de calques
	os << tab_calque.size() << std::endl;
	os << std::endl;

	//Sauvegarde les points
	os << tab_point.size() << std::endl;
	for (size_t i = 0; i < tab_point.size(); i++) os << getIndex(getCalque(tab_point[i])) << ' ' << (*tab_point[i]) << std::endl;

	os << std::endl;
	//Sauvegarde les formes
	os << tab_forme.size() << std::endl;
	for (size_t i = 0; i < tab_forme.size(); i++) os << getIndex(getCalque(tab_point[i])) << ' ' << (*tab_forme[i]) << std::endl;	
}

void Gestionnaire::charger(std::istream & is) {
	//Remet tout a zero
	for (size_t i = 0; i < tab_forme.size(); i++) delete tab_forme[i];
	tab_forme.clear();
	for (size_t i = 0; i < tab_point.size(); i++) delete tab_point[i];
	tab_point.clear();
	for (size_t i = 0; i < tab_calque.size(); i++) delete tab_calque[i];
	tab_calque.clear();
	for (size_t i = 0; i < tab_groupe.size(); i++) delete tab_groupe[i];
	tab_groupe.clear();

	tab_groupe.push_back(new Groupe());

	size_t nb;

	//Charge les calques
	is >> nb;
	for (size_t i = 0; i < nb; ++i) ajouter(new Calque());

	//Charge les points
	is >> nb;
	for (size_t i = 0; i < nb; ++i) {
		try {
			ajouter(PointD::charger(is), getCalqueIndex(is));
		} catch (std::runtime_error & e) {
			std::cerr << e.what() << std::endl;
		}
	}

	//Charge les formes
	is >> nb;
	for (size_t i = 0; i < nb; ++i) {
		try {
			ajouter(FormeD::charger(is), getCalqueIndex(is));
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

void Gestionnaire::shapeToLayer(FormeD * shape, size_t index) {
	getCalque(shape)->supprimer(shape);
	tab_calque.at(index)->ajouter(shape);
}

void Gestionnaire::groupeToLayer(Groupe * groupe, size_t index) {
	for (size_t i = 0; i < groupe->getNbFormes(); ++i)
		shapeToLayer(groupe->getFormeAt(i), index);
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
		if (tab_calque[i]->isActive()) {
			FormeD* forme = tab_calque[i]->isOverForme(x, y);
			if (forme != nullptr)
				return forme;
		}
	}
	return nullptr;
}

PointD * Gestionnaire::isOverPoint(int x, int y) const {
	for (size_t i = tab_calque.size() - 1; i >= 0 && i < tab_calque.size(); i--) {
		if (tab_calque[i]->isActive()) {
			PointD * point = tab_calque[i]->isOverPoint(x, y);
			if (point != nullptr)
				return point;
		}
	}
	return nullptr;
}

Calque * Gestionnaire::getCalque(FormeD * shape) const {
	for (size_t i = 0; i < tab_calque.size(); i++) {
		if (tab_calque[i]->isInTab(shape)) return tab_calque[i];
	}
	return nullptr;
}

Calque * Gestionnaire::getCalque(PointD * point) const {
	for (size_t i = 0; i < tab_calque.size(); i++) {
		if (tab_calque[i]->isInTab(point)) return tab_calque[i];
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

size_t Gestionnaire::getIndex(FormeD * forme) const {
	for (size_t i = 0; i < tab_forme.size(); i++) {
		if (tab_forme[i] == forme) return i;
	}
	throw std::domain_error("La forme n'existe pas");
}

std::vector<PointD*>* Gestionnaire::getPartagedPoint() const {
	std::vector<PointD*> * tab_partage = new std::vector<PointD*>();
	for (size_t i = 0; i < tab_point.size(); ++i)
		if (tab_point[i]->isPartaged()) tab_partage->push_back(tab_point[i]);

	return tab_partage;
}

size_t Gestionnaire::getIndex(PointD * point) const {
	for (size_t i = 0; i < tab_point.size(); i++) {
		if (tab_point[i] == point) return i;
	}
	throw std::domain_error("Le point n'existe pas");
}

size_t Gestionnaire::getIndex(Calque * calque) const {
	for (size_t i = 0; i < tab_calque.size(); i++) {
		if (tab_calque[i] == calque) return i;
	}
	throw std::domain_error("Le calque n'existe pas");
}

inline size_t Gestionnaire::getCalqueIndex(std::istream & is) {
	size_t index;
	is >> index;
	return index;
}
