#ifndef CALQUE_HPP
#define CALQUE_HPP

#include <iostream>
#include <vector>

#include "FormeDrawable.hpp"
#include "SFML/Graphics.hpp"

class Calque {
	bool active;
	std::vector<FormeD*> * tab_forme;
	std::vector<PointD*> * tab_point;

	public:
		Calque(bool active = true);
		~Calque();
		void ajouter(FormeD *shape);
		void ajouter(PointD * point);
		FormeD * isOverForme(int x, int y) const;
		PointD * isOverPoint(int x, int y) const;
		void dessiner(sf::RenderWindow &window) const;

		static Calque * charger(std::istream & is);

		inline size_t getNbFormes() const { return tab_forme->size(); }
		inline bool isActive() const { return active; }
		inline void toggleActive() { active = !active; }

		friend std::ostream & operator<<(std::ostream &os, const Calque &calque);
};

#endif CALQUE_HPP