#ifndef POINTSD_HPP
#define POINTSD_HPP

#include <iostream>

#include "PointDrawable.hpp"
#include "SFML/Graphics.hpp"

class PointsD {
	size_t max_points, nb_points;
	PointD** tab_points;

	public:
		PointsD(size_t taille = 200);
		~PointsD();
		void ajouter(PointD * p);
		PointD * isOver(int x, int y) const;
		void sauver(std::ostream &os) const;
		void charger(std::istream & is);
		void dessiner(sf::RenderWindow &window) const;

		inline size_t getNbPoints() { return nb_points; }
		inline PointD* getPointAt(size_t i) { return tab_points[i]; }
};

#endif POINTSD_HPP