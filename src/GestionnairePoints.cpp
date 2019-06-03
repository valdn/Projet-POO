#include "GestionnairePoints.hpp"

PointsD::PointsD(size_t taille) : max_points(taille), nb_points(0) {
	tab_points = new PointD*[max_points];
}

PointsD::~PointsD() {
	for (size_t i = 0; i < nb_points; i++) {
		delete tab_points[i];
	}
	delete[] tab_points;
}

void PointsD::ajouter(PointD * p) {
	if (nb_points >= max_points) throw std::runtime_error("Plus de place");
	else tab_points[nb_points++] = p;
}

void PointsD::dessiner(sf::RenderWindow & window) const {
	for (size_t i = 0; i < nb_points; i++) tab_points[i]->dessiner(window);
}

PointD * PointsD::isOver(int x, int y) const {
	for (size_t i = 0; i < nb_points; i++) {
		if (tab_points[i]->isOver(x, y)) return tab_points[i];
	}
	return nullptr;
}

void PointsD::sauver(std::ostream &os) const {
	os << max_points << std::endl << nb_points << std::endl;
	for (size_t i = 0; i < nb_points; i++) os << i << ' ' << (*tab_points[i]) << std::endl;
}

void PointsD::charger(std::istream &is) {
	for (size_t i = 0; i < nb_points; ++i) delete tab_points[i];
	delete[] tab_points;
	nb_points = 0;
	is >> max_points;
	tab_points = new PointD *[max_points];
	size_t cb;
	is >> cb;
	for (size_t i = 0; i < cb; ++i) ajouter(PointD::charger(is));
}
