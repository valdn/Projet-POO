#include "EllipseDrawable.hpp"

EllipseD::EllipseD(sf::Color couleur, uint x, uint y, uint demiLargeur, uint demiHauteur)
	: Forme(couleur.toInteger(), demiLargeur + x, demiHauteur + y),
		Ellipse(couleur.toInteger(), demiLargeur + x, demiHauteur + y, demiLargeur, demiHauteur),
		FormeD(couleur.toInteger(), demiLargeur + x, demiHauteur + y)
{	
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	update();
}

EllipseD::EllipseD(const EllipseD & ori) : EllipseD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getX(), ori.getDemiHauteur(), ori.getDemiLargeur()) {}

EllipseD::EllipseD(std::istream & is) : Forme(is), Ellipse(is), FormeD(is) {
	setFillColor(sf::Color(getCouleur()));
	setOutlineColor(sf::Color(getCouleur()));
	update();
}

EllipseD::~EllipseD() {}

//Faut pas oublier que l'ancre est au centre
bool EllipseD::isOver(uint _x, uint _y) const {
	return (std::pow(((double)_x - (double)getAncre().getX()) / getDemiLargeur(), 2) + std::pow(((double)_y - (double)getAncre().getY()) / getDemiHauteur(), 2) < 1);
}

void EllipseD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
}

inline void EllipseD::maj() {
	update();
}

std::size_t EllipseD::getPointCount() const {
	return 30;	//Fixé mais pas obligé. Retourne 30 points qui vont définir la forme
}

sf::Vector2f EllipseD::getPoint(std::size_t index) const {
	float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
	float x = std::cos(angle) * getDemiLargeur();
	float y = std::sin(angle) * getDemiHauteur();

	return sf::Vector2f(x + getAncre().getX(), y + getAncre().getY());
}
