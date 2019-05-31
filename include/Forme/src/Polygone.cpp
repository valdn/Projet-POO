#include "Forme/Polygone.hpp"

namespace fm {

void Polygone::ecrire(std::ostream &os) const {
	os << "Triangle ";
	Forme::ecrire(os);
	//os << p1 << ' ' << p2 << ' ';
}

Polygone::Polygone(uint couleur, int x, int y, std::vector<Point*>* _tabPoint) : Forme(couleur, x, y), tabPoint(_tabPoint), taille_tab(0) {
	if (tabPoint != nullptr) {
		taille_tab = tabPoint->size();
	}
}

Polygone::Polygone(const Polygone & ori) : Polygone(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.getTabPointPtr()) {}

Polygone::Polygone(std::istream &is) : Forme(is) {
	//TODO
}

Polygone::~Polygone() {}

double Polygone::perimetre() const {
	double perimetre = 0;
	size_t i = 0;	//Défini i en dehors du fort pour s'en reservir plus tard

	if (tabPoint == nullptr) throw "il n'y a aucun point dans le polygone";

	//Ajoute au périmètre la distance entre deux point
	//Exemple si y'a 4 point ça va calculer la distance entre p1-p2 puis p2-p3 puis p3-p4
	for (; i < taille_tab - 1; i++) {
		perimetre += getLonSeg( (*getPointAt(i)), (*getPointAt(i+1)) );
	}

	//Ajoute la dernière distance a calculer dernier point - premier point, p4-p1
	perimetre += getLonSeg((*getPointAt(i)), (*getPointAt(0)));

	return perimetre;
}

}//namespace
