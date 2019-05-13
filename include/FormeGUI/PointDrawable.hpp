#ifndef POINT_DRAWABLE_HPP
#define POINT_DRAWABLE_HPP

#include "Forme/Point.hpp"
#include "SFML/Graphics.hpp"

class PointD : public fm::Point, public sf::Drawable {

	sf::Color couleur;

public:
	bool isOver(uint _x, uint _y) const;
	void dessiner(sf::RenderWindow & window);
};

#endif POINT_DRAWABLE_HPP