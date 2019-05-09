#ifndef FORMES_HPP
#define FORMES_HPP

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Forme.hpp"

typedef unsigned long ulong;
typedef unsigned int uint;

class Formes : public sf::Drawable {
	size_t max_formes;
	size_t nb_formes;
	Forme **tab_formes;

	public:
		Formes(size_t taille = 200);
		~Formes();
		void ajouter(Forme *forme);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		Forme * isOver(uint x, uint y) const;
		void sauver(std::ostream &os) const;
		void charger(std::istream & is);
		friend std::ostream &operator<<(std::ostream &os, const Forme &tab_forme);
};

#endif