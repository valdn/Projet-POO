#include "GestionnaireFormes.hpp"

FormesD::FormesD(size_t taille) : max_formes(taille), nb_drawable(0) {
	tab_drawable = new FormeD*[max_formes];
}

FormesD::~FormesD() {
	for (size_t i = 0; i < nb_drawable; i++) {
		delete tab_drawable[i];
	}
	delete[] tab_drawable;
}

void FormesD::ajouter(FormeD * shape) {
	if (nb_drawable >= max_formes) throw std::runtime_error("Plus de place");
	else tab_drawable[nb_drawable++] = shape;
}

void FormesD::dessiner(sf::RenderWindow & window) const {
	for (size_t i = 0; i < nb_drawable; i++) tab_drawable[i]->dessiner(window);
}

void FormesD::update() const {
	for (size_t i = 0; i < nb_drawable; i++) tab_drawable[i]->recalculate();
}

ImageD * FormesD::getImageByPoint(PointD * p1) const {
	for (size_t i = 0; i < nb_drawable; i++) {
		ImageD * test = dynamic_cast<ImageD*> (tab_drawable[i]);
		if (test != nullptr && test->getPointD() == p1) return test;
	}
	return nullptr;
}

FormeD * FormesD::isOver(int x, int y) const {
	for (size_t i = 0; i < nb_drawable; i++) {
		if (tab_drawable[i]->isOver(x, y)) return tab_drawable[i];
	}
	return nullptr;
}

void FormesD::sauver(std::ostream &os) const {
	os << max_formes << std::endl << nb_drawable << std::endl;
	for (size_t i = 0; i < nb_drawable; i++) os << (*tab_drawable[i]) << std::endl;
}

void FormesD::charger(std::istream &is) {
	for (size_t i = 0; i < nb_drawable; ++i) delete tab_drawable[i];
	delete[] tab_drawable;
	nb_drawable = 0;
	is >> max_formes;
	tab_drawable = new FormeD *[max_formes];
	size_t cb;
	is >> cb;
	for (size_t i = 0; i < cb; ++i) ajouter(FormeD::charger(is));
}
