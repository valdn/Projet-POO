#include "PointDrawable.hpp"

bool PointD::isOver(uint _x, uint _y) const {
	return ((_x >= getX() - getTaille()) && (_x <= getX() + getTaille()) && (_y >= getY() - getTaille()) && (_y <= getY() + getTaille()));
}

void PointD::dessiner(sf::RenderWindow & window) {
	sf::CircleShape c(getTaille() / 2);
	window.draw(c);
}
