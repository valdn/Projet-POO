#ifndef FORMESD_HPP
#define FORMESD_HPP

#include <iostream>

#include "FormeDrawable.hpp"
#include "SFML/Graphics.hpp"

class FormesD {
	size_t max_formes, nb_drawable;
	FormeD** tab_drawable;

	public:
		FormesD(size_t taille = 200);
		~FormesD();
		void ajouter(FormeD *shape);
		FormeD * isOver(int x, int y) const;
		void sauver(std::ostream &os) const;
		void charger(std::istream & is);
		void dessiner(sf::RenderWindow &window) const;
		void update() const;

		inline size_t getnbFormes() { return nb_drawable; }
};

#endif FORMESD_HPP