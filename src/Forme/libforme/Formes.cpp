#include "Formes.hpp"

Formes::Formes(size_t taille) : max_formes(taille), nb_formes(0), tab_formes(nullptr) {
	tab_formes = new Forme*[max_formes];
}

Formes::~Formes() {
	for (size_t i = 0; i < nb_formes; i++) {
		delete tab_formes[i];
	}
	delete[] tab_formes;
}

void Formes::ajouter(Forme * forme) {
	if (nb_formes >= max_formes) throw std::runtime_error("Plus de place");
	else tab_formes[nb_formes++] = forme;
}

void Formes::dessiner(sf::RenderWindow & window) {
	for (size_t i = 0; i < nb_formes; ++i)
		tab_formes[i]->dessiner(window);
}


Forme * Formes::isOver(uint x, uint y) const {
	for (size_t i = 0; i < nb_formes; i++) {
		if (tab_formes[i]->isOver(x, y)) return tab_formes[i];
	}
	return nullptr;
}

void Formes::sauver(std::ostream &os) const {
	os << max_formes << std::endl << nb_formes << std::endl;
	for (size_t i = 0; i < nb_formes; i++) os << (*tab_formes[i]) << std::endl;
}

void Formes::charger(std::istream &is) {
	for (size_t i = 0; i < nb_formes; ++i) delete tab_formes[i];
	delete[] tab_formes;
	nb_formes = 0;
	is >> max_formes;
	tab_formes = new Forme *[max_formes];
	size_t cb;
	is >> cb;
	for (size_t i = 0; i < cb; ++i) ajouter(Forme::charger(is));
}

