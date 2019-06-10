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
		void supprimer(FormeD *shape);
		void supprimer(PointD *point);
		FormeD * isOverForme(int x, int y) const;
		PointD * isOverPoint(int x, int y) const;
		void dessiner(sf::RenderWindow &window) const;
		bool isInTab(FormeD * shape) const;
		bool isInTab(PointD * point) const;

		inline size_t getNbFormes() const { return tab_forme->size(); }
		inline size_t getNbPoints() const { return tab_point->size(); }
		inline FormeD* getFormeAt(size_t i) const { return tab_forme->at(i); }
		inline PointD* getPointAt(size_t i) const { return tab_point->at(i); }
		inline bool isActive() const { return active; }
		inline void toggleActive() { active = !active; }

		friend std::ostream & operator<<(std::ostream &os, const Calque &calque);

	private:
		size_t getPosShape(FormeD * shape) const; 
		size_t getPosPoint(PointD * point) const; 
};

#endif CALQUE_HPP