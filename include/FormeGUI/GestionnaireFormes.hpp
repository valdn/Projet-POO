#ifndef FORMESD_HPP
#define FORMESD_HPP

#include <iostream>

#include "FormeDrawable.hpp"
#include "SFML/Graphics.hpp"

typedef unsigned int uint;

class FormesD {
	size_t max_formes, nb_drawable;
	FormeD** tab_drawable;

	public:
		FormesD(size_t taille = 200);
		~FormesD();
		void ajouter(FormeD *shape);
		FormeD * isOver(uint x, uint y) const;
		void sauver(std::ostream &os) const;
		void charger(std::istream & is);
		void dessiner(sf::RenderWindow &window) const;
};

#endif FORMESD_HPP