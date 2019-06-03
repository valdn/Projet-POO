#ifndef GESTION_HPP
#define GESTION_HPP

#include <iostream>

#include "FormeDrawable.hpp"
#include "PointDrawable.hpp"
#include "Calque.hpp"
#include "ImageDrawable.hpp"

class Gestionnaire {
	std::vector<FormeD*> tab_forme;
  std::vector<PointD*> tab_point;
  std::vector<Calque*> tab_calque;

	public:
		Gestionnaire();
		~Gestionnaire();

		void ajouter(FormeD * forme, size_t num_calque = 0);
		void ajouter(PointD * point, size_t num_calque = 0);
		void ajouter(Calque * calque);

		void sauver(std::ostream &os) const;
		void charger(std::istream & is);
		void update() const;
		void dessiner(sf::RenderWindow &window) const;

		ImageD * getImageByPoint(PointD* p1) const;
		FormeD * isOverForme(int x, int y) const;
		PointD * isOverPoint(int x, int y) const;

		inline size_t getNbFormes() const { return tab_forme.size(); }
		inline FormeD* getFormeAt(size_t i) const { return tab_forme[i]; }
		inline size_t getNbPoints() const { return tab_point.size(); }
		inline PointD* getPointAt(size_t i) const { return tab_point[i]; }
		inline size_t getNbCalque() const { return tab_calque.size(); }
		inline Calque* getCalqueAt(size_t i) const { return tab_calque[i]; }
};

#endif GESTION_HPP