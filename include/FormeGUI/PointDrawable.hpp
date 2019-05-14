#ifndef POINT_DRAWABLE_HPP
#define POINT_DRAWABLE_HPP

#include "SFML/Graphics.hpp"
#include "Forme/Point.hpp"

class PointD {
	sf::Color couleur;
	fm::Point * ancre;
	sf::CircleShape cercle;

	public:
		PointD(fm::Point * _ancre, sf::Color couleur = sf::Color::Black);
		void update();
		void dessiner(sf::RenderWindow & window) const;
		bool isOver(uint x, uint y) const;
};

#endif POINT_DRAWABLE_HPP