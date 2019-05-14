#include "..\include\FormeGUI\PointDrawable.hpp"

PointD::PointD(fm::Point * _ancre, sf::Color _couleur) : ancre(_ancre), couleur(_couleur) {
	cercle.setFillColor(sf::Color::Black);
	cercle.setRadius((float)ancre->getTaille());
	cercle.setOrigin(cercle.getRadius(), cercle.getRadius());
	update();
}

void PointD::update() {
	cercle.setPosition((float)ancre->getX(), (float)ancre->getY());
}

void PointD::dessiner(sf::RenderWindow & window) const {
	window.draw(cercle);
}

bool PointD::isOver(uint x, uint y) const {
	//retourne vrai si la distance entre le centre du cerlce et la souris est inférieur au rayon
	return ((std::pow((double)x - (double)ancre->getX(), 2) + std::pow((double)y - (double)ancre->getY(), 2)) <= std::pow(ancre->getTaille(),2));
}
